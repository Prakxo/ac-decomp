#include "dolphin/OSContext.h"

static asm void __OSLoadFPUContext(int unused, register OSContext* ctx){
	nofralloc
	lhz r5, ctx->SHORT_0x1A2
	clrlwi. r5, r5, 0x1f
	beq exit
	
	lfd f0, ctx->fpscr_temp
	mtfs f0
	mfspr r5, 0x398
	rlwinm. r5, r5, 3, 0x1f, 0x1f
	beq load_fprs
	
	psq_l f0, 0x1C8(ctx), 0, 0
    psq_l f1, 0x1D0(ctx), 0, 0
    psq_l f2, 0x1D8(ctx), 0, 0
    psq_l f3, 0x1E0(ctx), 0, 0
    psq_l f4, 0x1E8(ctx), 0, 0
    psq_l f5, 0x1F0(ctx), 0, 0
    psq_l f6, 0x1F8(ctx), 0, 0
    psq_l f7, 0x200(ctx), 0, 0
    psq_l f8, 0x208(ctx), 0, 0
    psq_l f9, 0x210(ctx), 0, 0
    psq_l f10, 0x218(ctx), 0, 0
    psq_l f11, 0x220(ctx), 0, 0
    psq_l f12, 0x228(ctx), 0, 0
    psq_l f13, 0x230(ctx), 0, 0
    psq_l f14, 0x238(ctx), 0, 0
    psq_l f15, 0x240(ctx), 0, 0
    psq_l f16, 0x248(ctx), 0, 0
    psq_l f17, 0x250(ctx), 0, 0
    psq_l f18, 0x258(ctx), 0, 0
    psq_l f19, 0x260(ctx), 0, 0
    psq_l f20, 0x268(ctx), 0, 0
    psq_l f21, 0x270(ctx), 0, 0
    psq_l f22, 0x278(ctx), 0, 0
    psq_l f23, 0x280(ctx), 0, 0
    psq_l f24, 0x288(ctx), 0, 0
    psq_l f25, 0x290(ctx), 0, 0
    psq_l f26, 0x298(ctx), 0, 0
    psq_l f27, 0x2A0(ctx), 0, 0
    psq_l f28, 0x2A8(ctx), 0, 0
    psq_l f29, 0x2B0(ctx), 0, 0
    psq_l f30, 0x2B8(ctx), 0, 0
    psq_l f31, 0x2C0(ctx), 0, 0
	
load_fprs:
    lfd f0, ctx->fprs[0]
    lfd f1, ctx->fprs[1]
    lfd f2, ctx->fprs[2]
    lfd f3, ctx->fprs[3]
    lfd f4, ctx->fprs[4]
    lfd f5, ctx->fprs[5]
    lfd f6, ctx->fprs[6]
    lfd f7, ctx->fprs[7]
    lfd f8, ctx->fprs[8]
    lfd f9, ctx->fprs[9]
    lfd f10, ctx->fprs[10]
    lfd f11, ctx->fprs[11]
    lfd f12, ctx->fprs[12]
    lfd f13, ctx->fprs[13]
    lfd f14, ctx->fprs[14]
    lfd f15, ctx->fprs[15]
    lfd f16, ctx->fprs[16]
    lfd f17, ctx->fprs[17]
    lfd f18, ctx->fprs[18]
    lfd f19, ctx->fprs[19]
    lfd f20, ctx->fprs[20]
    lfd f21, ctx->fprs[21]
    lfd f22, ctx->fprs[22]
    lfd f23, ctx->fprs[23]
    lfd f24, ctx->fprs[24]
    lfd f25, ctx->fprs[25]
    lfd f26, ctx->fprs[26]
    lfd f27, ctx->fprs[27]
    lfd f28, ctx->fprs[28]
    lfd f29, ctx->fprs[29]
    lfd f30, ctx->fprs[30]
    lfd f31, ctx->fprs[31]
	
exit:
	blr
}

static asm void __OSSaveFPUContext( int unused, int unused1, register OSContext* ctx){
	nofralloc
	lhz r3, ctx->SHORT_0x1A2
	ori r3, r3, 1
	sth r3, ctx->SHORT_0x1A2
	
	    stfd f0, ctx->fprs[0]
    stfd f1, ctx->fprs[1]
    stfd f2, ctx->fprs[2]
    stfd f3, ctx->fprs[3]
    stfd f4, ctx->fprs[4]
    stfd f5, ctx->fprs[5]
    stfd f6, ctx->fprs[6]
    stfd f7, ctx->fprs[7]
    stfd f8, ctx->fprs[8]
    stfd f9, ctx->fprs[9]
    stfd f10, ctx->fprs[10]
    stfd f11, ctx->fprs[11]
    stfd f12, ctx->fprs[12]
    stfd f13, ctx->fprs[13]
    stfd f14, ctx->fprs[14]
    stfd f15, ctx->fprs[15]
    stfd f16, ctx->fprs[16]
    stfd f17, ctx->fprs[17]
    stfd f18, ctx->fprs[18]
    stfd f19, ctx->fprs[19]
    stfd f20, ctx->fprs[20]
    stfd f21, ctx->fprs[21]
    stfd f22, ctx->fprs[22]
    stfd f23, ctx->fprs[23]
    stfd f24, ctx->fprs[24]
    stfd f25, ctx->fprs[25]
    stfd f26, ctx->fprs[26]
    stfd f27, ctx->fprs[27]
    stfd f28, ctx->fprs[28]
    stfd f29, ctx->fprs[29]
    stfd f30, ctx->fprs[30]
    stfd f31, ctx->fprs[31]
	
	mffs f0
	stfd f0, ctx->fpscr_tmp
	lfd f0, ctx->fprs[0]
	mfspr r3, 0x398
	rlwinm. r3, r3, 3, 0x1f, 0x1f
	beq exit
	
	    psq_st f0, 0x1C8(ctx), 0, 0
    psq_st f1, 0x1D0(ctx), 0, 0
    psq_st f2, 0x1D8(ctx), 0, 0
    psq_st f3, 0x1E0(ctx), 0, 0
    psq_st f4, 0x1E8(ctx), 0, 0
    psq_st f5, 0x1F0(ctx), 0, 0
    psq_st f6, 0x1F8(ctx), 0, 0
    psq_st f7, 0x200(ctx), 0, 0
    psq_st f8, 0x208(ctx), 0, 0
    psq_st f9, 0x210(ctx), 0, 0
    psq_st f10, 0x218(ctx), 0, 0
    psq_st f11, 0x220(ctx), 0, 0
    psq_st f12, 0x228(ctx), 0, 0
    psq_st f13, 0x230(ctx), 0, 0
    psq_st f14, 0x238(ctx), 0, 0
    psq_st f15, 0x240(ctx), 0, 0
    psq_st f16, 0x248(ctx), 0, 0
    psq_st f17, 0x250(ctx), 0, 0
    psq_st f18, 0x258(ctx), 0, 0
    psq_st f19, 0x260(ctx), 0, 0
    psq_st f20, 0x268(ctx), 0, 0
    psq_st f21, 0x270(ctx), 0, 0
    psq_st f22, 0x278(ctx), 0, 0
    psq_st f23, 0x280(ctx), 0, 0
    psq_st f24, 0x288(ctx), 0, 0
    psq_st f25, 0x290(ctx), 0, 0
    psq_st f26, 0x298(ctx), 0, 0
    psq_st f27, 0x2A0(ctx), 0, 0
    psq_st f28, 0x2A8(ctx), 0, 0
    psq_st f29, 0x2B0(ctx), 0, 0
    psq_st f30, 0x2B8(ctx), 0, 0
    psq_st f31, 0x2C0(ctx), 0, 0
	
exit:
	blr
}

asm void OSSetCurrentContext(register OSContext* ctx){
	nofralloc
	lis r4, 0x8000
	stw ctx, OS_GET_CURRENT_CONTEXT@l(r4)
	clrlwi r5, ctx, 2
	stw r5, OS_CURRENT_CONTEXT_PHYS@l(r4)
	lwz r5, OS_CURRENT_FPU_CONTEXT@l(r4)
	cmpw r5, ctx
	bne not_cur_fpu_ctx
	
	lwz r6, ctx->srr1
	ori r6, r6, 0x2000
	stw r6, ctx->srr1
	mfmsr r6
	ori r6, r6, 2
	mtmsr r6
	blr
	
not_cur_fpu_ctx:
	lwz r6, ctx->srr1
	rlwinm r6, r6, 0, 0x13, 0x11
	stw r6, ctx->srr1
	mfmsr r6
	rlwinm r6, r6, 0, 0x13, 0x11
	ori r6, r6, 2
	mtmsr r6
	isync
	blr
}

OSContext* OSGetCurrentContext(void) {
	return(OS_CURRENT_CONTEXT)
}

asm BOOL OSSaveContext(register OSContext* ctx){
	nofralloc
	stmw r13, ctx->gprs[13]
	mfspr r0, 0x391
	stw r3, ctx->gqrs[1]
	mfspr r0, 0x392
	stw r3, ctx->gqrs[2]
	mfspr r0, 0x393
	stw r3, ctx->gqrs[3]
	mfpsr r0, 0x394
	stw r3, ctx->gqrs[4]
	mfspr r0, 0x395
	stw r3, ctx->gqrs[5]
	mfpsr r0, 0x396
	stw r3, ctx->gqrs[6]
	mfspr r0, 0x397
	stw r3, ctx->gqrs[7]
	
	mfcr r0
	
	stw r3, ctx->cr
	mflr r0
	stw r3, ctx->lr
	stw r3, ctx->srr0
	mfmsr r0
	
	stw r3, ctx->srr1
	mfctr r0
	
	stw r3, ctx->ctr
	mfxer r0
	
	stw r3, ctx->xer
	
	stw r1, ctx->gprs[1]
	stw r2, ctx->gprs[2]
	li r0, 1
	li r0, 0x0c(r3)
	li r3, 0
	
	blr	
}

/* asm void OSLoadContext(register OSContext* ctx){
	nofralloc
	
} */