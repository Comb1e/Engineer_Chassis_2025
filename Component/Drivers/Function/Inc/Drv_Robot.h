//
// Created by CYK on 2024/11/29.
//

#ifndef DRV_ROBOT_H
#define DRV_ROBOT_H

#include "Drv_Chassis.h"
#include "Drv_Gimbal.h"
#include "RTOS.h"
#include "Global_CFG.h"
#include "Drv_Arm.h"
#include "Drv_Absorb.h"
#include "Drv_Keyboard.h"
#include "Drv_Info.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
}
#endif

typedef enum
{
    MODE_NONE,
    STEER_MODE,
    MINE_MODE
}kb_control_mode_e;

typedef enum
{
    RC_KB_CONTROL = 0,//键盘遥控器
    VISUAL_CONTROL,//视觉
    AUTO_CONTROL,//自动化模块
}robot_control_mode_e;

typedef enum
{
    AutoOK = 0,
    AutoError = -1,
    AutoErrorTimeout = -2,
    AutoSuspend = -3,
}autoStatus_e;

typedef enum
{
    Auto_None = 0,
    Big_Island,
    Small_Island,
    Exchange_Mine,
    Ground_Mine,
}autoSituation_e;

class Robot_Device
{
private:

public:
    Robot_Device();

    bool enable_flag;

    bool select_left_flag;
    bool select_right_flag;
    bool select_center_flag;
    bool cancel_flag;

    sucker_e store_sucker;

    kb_control_mode_e kb_control_mode;
    robot_control_mode_e control_mode;

    void Set_Control_Mode(robot_control_mode_e control_mode);

    void Set_KB_Control_Mode_Mine();
    void Set_KB_Control_Mode_Steer();

    void RC_Set_Chassis_Vel_X(float vel_x);
    void RC_Set_Chassis_Vel_Y(float vel_y);
    void RC_Set_Chassis_Vel_Spin(float vel_spin);
    void RC_Set_Chassis_Vel(float vel_x,float vel_y,float vel_spin);

    void RC_Set_Chasssis_Position(float pos_x,float pos_y,float pos_spin);

    void RC_Set_Gimbal_Position(float delta);

    void Sucker_Directional_Move(traj_item_e point, float delta_distance);

    void Set_Select_Left_Flag();
    void Set_Select_Right_Flag();
    void Set_Select_Center_Flag();
    void Set_Cancel_Flag();
    bool Check_Select_Center();
    bool Check_Select_Right();
    bool Check_Select_Left();
    bool Check_Cancel();

    float Get_Arm_Point_Limit_Chassis_Val();
    void Update_Chassis_Speed_Limit();

    void Check_Rot();
    void Check_KB_Event();

    void Adjust_Ore();
    void Set_Store_Sucker();

    void Gimbal_Reset();
    void Arm_Homing();
    void Sucker_Reset();

    void Turn_Chassis_Back();

    void Exchange_Five_Grade();
    void Left_Exchange_Five_Grade();
    void Right_Exchange_Five_Grade();

    void Exchange_Four_Grade();
    void Left_Exchange_Four_Grade();
    void Right_Exchange_Four_Grade();

/*----------automation----------*/
    autoStatus_e autoStatus;
    autoSituation_e autoSituation;

    osThreadId_t AutoSmallIslandHandle;
    osThreadId_t AutoBigIslandHandle;
    osThreadId_t AutoExchangeHandle;
    osThreadId_t AutoGroundMineHandle;

    const osThreadAttr_t AutoSmallIsland_Attributes;
    const osThreadAttr_t AutoBigIsland_Attributes;
    const osThreadAttr_t AutoExchange_Attributes;
    const osThreadAttr_t AutoGroundMine_Attributes;

    void Set_Auto_Situation(autoSituation_e autoSituation);
    void Creat_Task_Init();
    void Exit_Task();
//AutoExchange
    void CreatTask_Auto_Exchange();
    void ExitTask_AutoExchange();
//AutoBigIsland
    void CreatTask_Auto_BigIsland();
    void ExitTask_Auto_BigIsland();
//AutoSmallIsland
    void CreatTask_Auto_SmallIsland();
    void ExitTask_Auto_SmallIsland();
//AutoGroundMine
    void CreatTask_Auto_GroundMine();
    void ExitTask_Auto_GroundMine();
};

extern Robot_Device robot;

#endif //DRV_ROBOT_H
