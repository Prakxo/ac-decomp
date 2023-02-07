#ifndef FAULT_H
#define FAULT_H
#include "types.h"
#include "dolphin/OS/os.h"
#include "libultra/libultra.h"


#ifdef __cplusplus
extern "C"{
#endif

#define FAULT_MIN_PRIORITY 0

#define FAULT_STAGE_POST 0
#define FAULT_STAGE_PRE 1

#define FAULT_FLAG_POSTEXCEPTION (1 << FAULT_STAGE_POST)
#define FAULT_FLAG_PREEXCEPTION (1 << FAULT_STAGE_PRE)

#define FAULT_FLAG_DRAW_SEPARATOR (1 << 2)
#define FAULT_FLAG_DRAW_CALLBACK_INFO (1 << 3)

typedef struct { 
	fault_client* next;
	FaultCallBack callback;
	const char* msg;
	u32 param;
	u8 priority;
	u8 flags;
} fault_client;

typedef struct {
	u8 _0, _1, _2, _3;
	u8 num_clients;
	fault_client* first_client;
} fault;

typedef void (*FaultCallback)(const char* msg, u32 param);

void fault_AddClientEx(fault_client* client, FaultCallback callback, const char* msg, u32 param, u8 priority, u8 flags);
void fault_AddClient(fault_client* client, FaultCallback callback, const char* msg, u32 param);
void fault_Printf(const char* msg, ...);
void fault_DrawUpdate();
void fault_WaitTime(u32 waitTime);
int fault_ReadPad(u32* param_1, u32 param_2);
void fault_CallBackFunc(int stage);

void fault_Init();
static void my_PreExceptionCallback();
static void my_PostExceptionCallback();
#ifdef __cplusplus
}
#endif
#endif
