//
// Created by CYK on 2024/11/24.
//

#include "Tof_Check_Task.h"
#include "cmsis_os2.h"
#include "RTOS.h"

uint64_t tof_lost_num = 0;
uint64_t tof_connect_num = 0;
void Tof_Check_Task(void * argument)
{
    osSemaphoreAcquire(TofUpdateBinarySemHandle,10);
    for (;;)
    {
        osDelay(6);
        /*g_chassis.check_tof_for_loss();
        g_gimbal.check_motor_lost();
        if(g_chassis.check_tof_lost())
        {
            tof_lost_num++;
            tof_connect_num = 0;
        }
        else
        {
            tof_connect_num++;
            tof_lost_num = 0;
        }

        if(tof_connect_num > 10)
        {
            g_robot.disable_use_claw();
        }else if(tof_lost_num > 0)
        {
            g_robot.enable_use_claw();
        }*/
    }
}