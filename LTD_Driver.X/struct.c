#include "struct.h"
#include "DHT.h"

void InitializeElements() {
    for(int i = 0; i < MAX_NUM; i++) {
        elementList[i].Delay = elementList[i].Period = -1;
        elementList[i].next = elementList[i].task_identifier = elementList[i].isMark = -1;
        elementList[i].pTask = NULL;
        
        executedList[i] = NULL;
    }
}
  
TByte AddElement(uint64_t delay, uint64_t period, FUNCTION_PTR data, int task_id) {
    if(size == capacity) return -1;
    int index = 0;
    while(elementList[index].isMark == 1) {
        index = index + 1;
    }
    elementList[index].isMark = 1;
    elementList[index].Delay = delay;
    elementList[index].Period = period;
    elementList[index].next = -1;
    elementList[index].task_identifier = task_id;
    elementList[index].pTask = data;
    if(size == 0) {
        //LATD = 1;
        head = index;
        size++;
        return 0;
    }
    else {
        int pos = head;
        if(elementList[index].Delay < elementList[pos].Delay) {
            elementList[index].next = head;
            head = index;
            elementList[pos].Delay -= elementList[index].Delay;
            size++;
            return 0;
        }
        // Traverse to the last node
        int next_index;
        while(elementList[pos].next != -1){
            elementList[index].Delay -= elementList[pos].Delay;
            next_index = elementList[pos].next;
            if(elementList[index].Delay < elementList[next_index].Delay) {
                elementList[index].next = next_index;
                elementList[next_index].Delay -= elementList[index].Delay;
                elementList[pos].next = index;
                size++;
                return 0;
            }
            pos = elementList[pos].next;
        }
        // Last node
        elementList[index].Delay -= elementList[pos].Delay;
        elementList[pos].next = index;
        size++;
        return 0;
    }
}
 
void UpdateElements() {
    int pos = head;
    // Traverse till the last node
    if(elementList[pos].Delay > 0) {
        elementList[pos].Delay -= TICKS;
    }
    while(elementList[pos].Delay == 0 && pos != -1) {
        AddExecutedTask(elementList[pos].pTask);
        deQueue();
        pos = elementList[pos].next;
    }
    return;
}
 
void UpdateTimeOut() {
   // Set the TimeOut for each state
    if(idle_flag == 0 && error_flag == 0) {
        TimeOut -= TICKS;
        if(TimeOut == 0) {
            error_flag = 1;
        }
    }
    return;
}

int deQueue() {
    if(size == 0) return -1;
    else {
        int pos = head;
        head = elementList[pos].next;
        elementList[pos].next = -1;
        size--;
        elementList[pos].isMark = -1;
        if(elementList[pos].Period != 0) AddElement(elementList[pos].Period, elementList[pos].Period, elementList[pos].pTask, elementList[pos].task_identifier);
        return 0;
    }
}

int RemoveElement(int identifier) {
    if(size == 0) return -1;
    int pos = head;
    int next_index;
    if(identifier == elementList[pos].task_identifier && pos != -1) {
        head = elementList[pos].next;
        elementList[pos].next = -1;
        size--;
        elementList[pos].isMark = -1;
        elementList[pos].pTask = NULL;
        return 0;
    }
    while(elementList[pos].next != -1) {
        next_index = elementList[pos].next;
        if(identifier == elementList[next_index].task_identifier && pos != -1) {
            elementList[pos].next = elementList[next_index].next;
            elementList[next_index].next = -1;
            size--;
            elementList[next_index].isMark = -1;
            elementList[next_index].pTask = NULL;
            return 0;
        }
        pos = elementList[pos].next;
    }
    return -1;
}

void AddExecutedTask(FUNCTION_PTR data) {
    int pos = 0;
    while(executedList[pos] != NULL && pos <= MAX_NUM -1) pos++;
    executedList[pos] = data;
    return;
}

void dispatchISR() {
   int pos = 0;
   while(executedList[pos] != NULL && pos <= MAX_NUM - 1) {
        executedList[pos]();
        executedList[pos] = NULL;
        pos++;
   }
   return;
}
 