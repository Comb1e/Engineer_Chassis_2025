//
// Created by CYK on 2024/11/29.
//

#ifndef DRV_KEYBOARD_H
#define DRV_KEYBOARD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stm32f4xx_hal.h"
#include "Drv_RemoteCtrl.h"

#ifdef __cplusplus
}
#endif

class KB_Device {
private:
    void (*Key_Event[KeyNum])(enum KEY_DIR dir) ={
        KeyW_Event_Callback,
        KeyS_Event_Callback,
        KeyA_Event_Callback,
        KeyD_Event_Callback,
        KeySHIFT_Event_Callback,
        KeyCTRL_Event_Callback,
        KeyQ_Event_Callback,
        KeyE_Event_Callback,
        KeyR_Event_Callback,
        KeyF_Event_Callback,
        KeyG_Event_Callback,
        KeyZ_Event_Callback,
        KeyX_Event_Callback,
        KeyC_Event_Callback,
        KeyV_Event_Callback,
        KeyB_Event_Callback
    };

    void (*Key_State[KeyNum])(enum KEY_DIR dir) ={
        KeyW_State_Callback,
        KeyS_State_Callback,
        KeyA_State_Callback,
        KeyD_State_Callback,
        KeySHIFT_State_Callback,
        KeyCTRL_State_Callback,
        KeyQ_State_Callback,
        KeyE_State_Callback,
        KeyR_State_Callback,
        KeyF_State_Callback,
        KeyG_State_Callback,
        KeyZ_State_Callback,
        KeyX_State_Callback,
        KeyC_State_Callback,
        KeyV_State_Callback,
        KeyB_State_Callback
    };

public:



    void Check_RC_State();
    void Check_KB_State();
    void Check_Mouse_State();

    void Check_RC_Event();
    void Check_KB_Event();
    void Check_Mouse_Event();

    static void KeyW_State_Callback(enum KEY_DIR dir);
    static void KeyS_State_Callback(enum KEY_DIR dir);
    static void KeyA_State_Callback(enum KEY_DIR dir);
    static void KeyD_State_Callback(enum KEY_DIR dir);
    static void KeySHIFT_State_Callback(enum KEY_DIR dir);
    static void KeyCTRL_State_Callback(enum KEY_DIR dir);
    static void KeyQ_State_Callback(enum KEY_DIR dir);
    static void KeyE_State_Callback(enum KEY_DIR dir);
    static void KeyR_State_Callback(enum KEY_DIR dir);
    static void KeyF_State_Callback(enum KEY_DIR dir);
    static void KeyG_State_Callback(enum KEY_DIR dir);
    static void KeyZ_State_Callback(enum KEY_DIR dir);
    static void KeyX_State_Callback(enum KEY_DIR dir);
    static void KeyC_State_Callback(enum KEY_DIR dir);
    static void KeyV_State_Callback(enum KEY_DIR dir);
    static void KeyB_State_Callback(enum KEY_DIR dir);;

    static void KeyW_Event_Callback(enum KEY_DIR dir);
    static void KeyS_Event_Callback(enum KEY_DIR dir);
    static void KeyA_Event_Callback(enum KEY_DIR dir);
    static void KeyD_Event_Callback(enum KEY_DIR dir);
    static void KeySHIFT_Event_Callback(enum KEY_DIR dir);
    static void KeyCTRL_Event_Callback(enum KEY_DIR dir);
    static void KeyQ_Event_Callback(enum KEY_DIR dir);
    static void KeyE_Event_Callback(enum KEY_DIR dir);
    static void KeyR_Event_Callback(enum KEY_DIR dir);
    static void KeyF_Event_Callback(enum KEY_DIR dir);
    static void KeyG_Event_Callback(enum KEY_DIR dir);
    static void KeyZ_Event_Callback(enum KEY_DIR dir);
    static void KeyX_Event_Callback(enum KEY_DIR dir);
    static void KeyC_Event_Callback(enum KEY_DIR dir);
    static void KeyV_Event_Callback(enum KEY_DIR dir);
    static void KeyB_Event_Callback(enum KEY_DIR dir);;
};

extern KB_Device kb;

#endif //DRV_KEYBOARD_H