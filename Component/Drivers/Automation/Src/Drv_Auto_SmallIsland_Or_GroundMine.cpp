//
// Created by CYK on 2024/12/19.
//

#include "Drv_Auto_SmallIsland_Or_GroundMine.h"

void Robot_Device::Pre_For_Auto_SmallIsland_Or_GroundMine()
{
    this->gimbal->Set_Pitch_Deg(40.0f);
    this->info->Set_Pose_Mode(single);
    osDelay(3);
}

void Robot_Device::SmallIsland_Or_GroundMine_Pre()
{
    this->arm->Set_Point_Target_Pos_Vel(YAW,GROUND_MINE_PRE_POSITION_YAW,GROUND_MINE_PRE_POSITION_RYP_VEL);
    this->arm->Set_Point_Target_Pos_Vel(PITCH,GROUND_MINE_PRE_POSITION_PITCH,GROUND_MINE_PRE_POSITION_RYP_VEL);
    this->arm->Set_Point_Target_Pos_Vel(ROLL,GROUND_MINE_PRE_POSITION_ROLL,GROUND_MINE_PRE_POSITION_RYP_VEL);
    this->arm->Wait_For_Moving();

    this->arm->Set_Point_Target_Pos_Vel(ARM_YAW,GROUND_MINE_PRE_POSITION_ARM_YAW,GROUND_MINE_PRE_POSITION_RYP_VEL);
    this->arm->Set_Point_Target_Pos_Vel(ARM_PITCH,GROUND_MINE_PRE_POSITION_ARM_PITCH,GROUND_MINE_PRE_POSITION_RYP_VEL);
    this->arm->Wait_For_Moving();

    this->arm->Set_Point_Target_Pos_Vel(X,GROUND_MINE_PRE_POSITION_X,GROUND_MINE_PRE_POSITION_XYZ_VEL);
    this->arm->Set_Point_Target_Pos_Vel(Y,GROUND_MINE_PRE_POSITION_Y,GROUND_MINE_PRE_POSITION_XYZ_VEL);
    this->arm->Set_Point_Target_Pos_Vel(Z,GROUND_MINE_PRE_POSITION_Z,GROUND_MINE_PRE_POSITION_XYZ_VEL);
    this->arm->Wait_For_Moving();
}

void Robot_Device::SmallIsland_Or_GroundMine_1()
{
    this->arm->Set_Point_Target_Pos_Vel(ARM_YAW,GROUND_MINE_PRE_POSITION_ARM_YAW,GROUND_MINE_1_POSITION_RYP_VEL);
    this->arm->Set_Point_Target_Pos_Vel(ARM_PITCH,GROUND_MINE_PRE_POSITION_ARM_PITCH,GROUND_MINE_1_POSITION_RYP_VEL);
    this->arm->Wait_For_Moving();

    this->arm->Set_Point_Target_Pos_Vel(X,GROUND_MINE_1_POSITION_X,GROUND_MINE_1_POSITION_XYZ_VEL);
    this->arm->Set_Point_Target_Pos_Vel(Z,GROUND_MINE_1_POSITION_Z,GROUND_MINE_1_POSITION_XYZ_VEL);
    this->arm->Wait_For_Moving();
}

void Robot_Device::SmallIsland_Or_GroundMine_Touching()
{
    this->absorb->Set_Sucker_Open(ARM_SUCKER);

    this->arm->Set_Point_Target_Pos_Vel(Z,GROUND_MINE_TOUCHING_POSITION_Z,GROUND_MINE_TOUCHING_POSITION_Z_VEL);
    while(!this->arm->Check_All_Get_To_Final() && !this->absorb->Check_Sucker_Holding(ARM_SUCKER))
    {
        osDelay(1);
    }
    this->arm->Set_FeedBack_As_Target();
}

void Robot_Device::SmallIsland_Or_GroundMine_Pre_Back()
{
    this->arm->Set_Point_Target_Pos_Vel(PITCH,GROUND_MINE_PRE_BACK_POSITION_PITCH,GROUND_MINE_PRE_BACK_POSITION_RYP_VEL);
    this->arm->Set_Point_Target_Pos_Vel(ARM_PITCH,GROUND_MINE_PRE_BACK_POSITION_ARM_PITCH,GROUND_MINE_PRE_BACK_POSITION_RYP_VEL);
    this->arm->Wait_For_Moving();

    this->arm->Set_Point_Target_Pos_Vel(X,GROUND_MINE_PRE_BACK_POSITION_X,GROUND_MINE_PRE_BACK_POSITION_XYZ_VEL);
    this->arm->Set_Point_Target_Pos_Vel(Z,GROUND_MINE_PRE_BACK_POSITION_Z,GROUND_MINE_PRE_BACK_POSITION_XYZ_VEL);
    this->arm->Wait_For_Moving();

    this->store_sucker = this->absorb->Find_To_Store();
    if(this->store_sucker == ORE_STORE_FULL)
    {
        this->store_sucker = ARM_SUCKER;
    }
}
