#include "clock.h"
#include "global_var.h"

int register_timer(uint64_t delay, uint64_t period, FUNCTION_PTR data) {
    int res = AddElement(delay, period, data, task);
    if(res == 0) {
        task++;
        return task - 1;
    }
    else return -1;
}

