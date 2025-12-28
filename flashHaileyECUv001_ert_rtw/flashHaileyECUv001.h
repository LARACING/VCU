/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: flashHaileyECUv001.h
 *
 * Code generated for Simulink model 'flashHaileyECUv001'.
 *
 * Model version                  : 10.66
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec  9 19:15:42 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flashHaileyECUv001_h_
#define RTW_HEADER_flashHaileyECUv001_h_
#ifndef flashHaileyECUv001_COMMON_INCLUDES_
#define flashHaileyECUv001_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "IO_DIO.h"
#include "IO_PWM.h"
#include "IO_CAN.h"
#include "IOLib500_utils.h"
#include "IO_ADC.h"
#include "IO_POWER.h"
#include "IO_PWD.h"
#endif                                 /* flashHaileyECUv001_COMMON_INCLUDES_ */

#include "flashHaileyECUv001_types.h"
#include <stddef.h>
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S202>/IO_DO_ResetProtection' */
typedef struct {
  uint16_T IO_DO_ResetProtection_s_o1; /* '<S206>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2;  /* '<S206>/IO_DO_ResetProtection_s' */
} rtB_IO_DO_ResetProtection_flash;

/* Zero-crossing (trigger) state for system '<S202>/IO_DO_ResetProtection' */
typedef struct {
  ZCSigState IO_DO_ResetProtection_Trig_Z_m3;/* '<S202>/IO_DO_ResetProtection' */
} rtZCE_IO_DO_ResetProtection_fla;

/* Block signals (default storage) */
typedef struct {
  real_T bit_unpacking_s;              /* '<S91>/bit_unpacking_s' */
  real_T t3;                           /* '<Root>/-t3' */
  real_T bit_unpacking_s_e;            /* '<S97>/bit_unpacking_s' */
  real_T bit_unpacking_s_d;            /* '<S68>/bit_unpacking_s' */
  real_T bit_unpacking_s_m;            /* '<S81>/bit_unpacking_s' */
  real_T bit_unpacking_s_dj;           /* '<S65>/bit_unpacking_s' */
  real_T bit_unpacking_s_b;            /* '<S66>/bit_unpacking_s' */
  real_T bit_unpacking_s_i;            /* '<S67>/bit_unpacking_s' */
  real_T bit_unpacking_s_dr;           /* '<S69>/bit_unpacking_s' */
  real_T bit_unpacking_s_a;            /* '<S70>/bit_unpacking_s' */
  real_T bit_unpacking_s_g;            /* '<S71>/bit_unpacking_s' */
  real_T bit_unpacking_s_p;            /* '<S72>/bit_unpacking_s' */
  real_T bit_unpacking_s_k;            /* '<S73>/bit_unpacking_s' */
  real_T bit_unpacking_s_o;            /* '<S74>/bit_unpacking_s' */
  real_T bit_unpacking_s_i5;           /* '<S75>/bit_unpacking_s' */
  real_T bit_unpacking_s_kt;           /* '<S78>/bit_unpacking_s' */
  real_T bit_unpacking_s_px;           /* '<S79>/bit_unpacking_s' */
  real_T bit_unpacking_s_dn;           /* '<S80>/bit_unpacking_s' */
  real_T bit_unpacking_s_pj;           /* '<S82>/bit_unpacking_s' */
  real_T bit_unpacking_s_j;            /* '<S83>/bit_unpacking_s' */
  real_T bit_unpacking_s_gj;           /* '<S84>/bit_unpacking_s' */
  real_T bit_unpacking_s_l;            /* '<S85>/bit_unpacking_s' */
  real_T bit_unpacking_s_bt;           /* '<S86>/bit_unpacking_s' */
  real_T bit_unpacking_s_ac;           /* '<S87>/bit_unpacking_s' */
  real_T bit_unpacking_s_jw;           /* '<S88>/bit_unpacking_s' */
  real_T bit_unpacking_s_bd;           /* '<S92>/bit_unpacking_s' */
  real_T bit_unpacking_s_ep;           /* '<S93>/bit_unpacking_s' */
  real_T bit_unpacking_s_ie;           /* '<S94>/bit_unpacking_s' */
  real_T bit_unpacking_s_bm;           /* '<S98>/bit_unpacking_s' */
  real_T bit_unpacking_s_c;            /* '<S99>/bit_unpacking_s' */
  real_T bit_unpacking_s_mt;           /* '<S100>/bit_unpacking_s' */
  real_T bit_unpacking_s_n;            /* '<S258>/bit_unpacking_s' */
  real_T bit_unpacking_s_ky;           /* '<S254>/bit_unpacking_s' */
  real_T Saturation;                   /* '<S14>/Saturation' */
  real_T bit_unpacking_s_nk;           /* '<S225>/bit_unpacking_s' */
  real_T bit_unpacking_s_pa;           /* '<S125>/bit_unpacking_s' */
  real_T bit_unpacking_s_mz;           /* '<S126>/bit_unpacking_s' */
  real_T bit_unpacking_s_jp;           /* '<S134>/bit_unpacking_s' */
  real_T bit_unpacking_s_el;           /* '<S135>/bit_unpacking_s' */
  real_T bit_unpacking_s_cx;           /* '<S121>/bit_unpacking_s' */
  real_T bit_unpacking_s_bm0;          /* '<S122>/bit_unpacking_s' */
  real_T bit_unpacking_s_lc;           /* '<S123>/bit_unpacking_s' */
  real_T bit_unpacking_s_h;            /* '<S124>/bit_unpacking_s' */
  real_T bit_unpacking_s_br;           /* '<S127>/bit_unpacking_s' */
  real_T bit_unpacking_s_gjh;          /* '<S130>/bit_unpacking_s' */
  real_T bit_unpacking_s_nks;          /* '<S131>/bit_unpacking_s' */
  real_T bit_unpacking_s_ef;           /* '<S132>/bit_unpacking_s' */
  real_T bit_unpacking_s_nf;           /* '<S133>/bit_unpacking_s' */
  real_T bit_unpacking_s_po;           /* '<S136>/bit_unpacking_s' */
  real_T Product9;                     /* '<Root>/Product9' */
  real_T bit_unpacking_s_mw;           /* '<S226>/bit_unpacking_s' */
  real_T bit_unpacking_s_eu;           /* '<S227>/bit_unpacking_s' */
  real_T bit_unpacking_s_pw;           /* '<S228>/bit_unpacking_s' */
  real_T bit_unpacking_s_i0;           /* '<S229>/bit_unpacking_s' */
  real_T bit_unpacking_s_ci;           /* '<S230>/bit_unpacking_s' */
  real_T Max1;                         /* '<Root>/Max1' */
  real_T Max2;                         /* '<Root>/Max2' */
  real_T bit_unpacking_s_lj;           /* '<S255>/bit_unpacking_s' */
  real_T bit_unpacking_s_d2;           /* '<S259>/bit_unpacking_s' */
  real_T bit_unpacking_s_j1;           /* '<S340>/bit_unpacking_s' */
  real_T bit_unpacking_s_n3;           /* '<S341>/bit_unpacking_s' */
  real_T bit_unpacking_s_mp;           /* '<S342>/bit_unpacking_s' */
  real_T bit_unpacking_s_cc;           /* '<S343>/bit_unpacking_s' */
  real_T bit_unpacking_s_iy;           /* '<S344>/bit_unpacking_s' */
  real_T bit_unpacking_s_ng;           /* '<S345>/bit_unpacking_s' */
  real_T bit_unpacking_s_ae;           /* '<S346>/bit_unpacking_s' */
  real_T bit_unpacking_s_lf;           /* '<S347>/bit_unpacking_s' */
  real_T bit_unpacking_s_n1;           /* '<S348>/bit_unpacking_s' */
  real_T bit_unpacking_s_jb;           /* '<S349>/bit_unpacking_s' */
  real_T bit_unpacking_s_no;           /* '<S350>/bit_unpacking_s' */
  real_T bit_unpacking_s_hr;           /* '<S351>/bit_unpacking_s' */
  real_T bit_unpacking_s_hc;           /* '<S352>/bit_unpacking_s' */
  real_T bit_unpacking_s_pt;           /* '<S353>/bit_unpacking_s' */
  real_T bit_unpacking_s_lg;           /* '<S354>/bit_unpacking_s' */
  real_T bit_unpacking_s_dt;           /* '<S355>/bit_unpacking_s' */
  real_T bit_unpacking_s_i1;           /* '<S356>/bit_unpacking_s' */
  real_T bit_unpacking_s_cr;           /* '<S357>/bit_unpacking_s' */
  real_T bit_unpacking_s_hr0;          /* '<S358>/bit_unpacking_s' */
  real_T bit_unpacking_s_a2;           /* '<S359>/bit_unpacking_s' */
  real_T bit_unpacking_s_je;           /* '<S360>/bit_unpacking_s' */
  real_T bit_unpacking_s_jv;           /* '<S361>/bit_unpacking_s' */
  real_T bit_unpacking_s_as;           /* '<S362>/bit_unpacking_s' */
  real_T bit_unpacking_s_pf;           /* '<S363>/bit_unpacking_s' */
  real_T bit_unpacking_s_dd;           /* '<S364>/bit_unpacking_s' */
  real_T bit_unpacking_s_ed;           /* '<S365>/bit_unpacking_s' */
  real_T bit_unpacking_s_ou;           /* '<S366>/bit_unpacking_s' */
  real_T bit_unpacking_s_dg;           /* '<S367>/bit_unpacking_s' */
  real_T bit_unpacking_s_p2;           /* '<S368>/bit_unpacking_s' */
  real_T bit_unpacking_s_iyi;          /* '<S369>/bit_unpacking_s' */
  real_T bit_unpacking_s_pm;           /* '<S370>/bit_unpacking_s' */
  real_T bit_unpacking_s_oc;           /* '<S371>/bit_unpacking_s' */
  real_T bit_unpacking_s_a0;           /* '<S372>/bit_unpacking_s' */
  real_T bit_unpacking_s_h0;           /* '<S373>/bit_unpacking_s' */
  real_T bit_unpacking_s_m3;           /* '<S374>/bit_unpacking_s' */
  real_T bit_unpacking_s_hd;           /* '<S375>/bit_unpacking_s' */
  real_T bit_unpacking_s_gz;           /* '<S376>/bit_unpacking_s' */
  real_T bit_unpacking_s_lq;           /* '<S377>/bit_unpacking_s' */
  real_T bit_unpacking_s_f;            /* '<S378>/bit_unpacking_s' */
  real_T bit_unpacking_s_au;           /* '<S379>/bit_unpacking_s' */
  real_T bit_unpacking_s_ja;           /* '<S380>/bit_unpacking_s' */
  real_T bit_unpacking_s_e4;           /* '<S381>/bit_unpacking_s' */
  real_T bit_unpacking_s_fy;           /* '<S382>/bit_unpacking_s' */
  real_T bit_unpacking_s_fh;           /* '<S383>/bit_unpacking_s' */
  real_T bit_unpacking_s_i5p;          /* '<S159>/bit_unpacking_s' */
  real_T bit_unpacking_s_an;           /* '<S162>/bit_unpacking_s' */
  real_T bit_unpacking_s_nr;           /* '<S163>/bit_unpacking_s' */
  real_T bit_unpacking_s_h4;           /* '<S166>/bit_unpacking_s' */
  real_T bit_unpacking_s_fp;           /* '<S167>/bit_unpacking_s' */
  real_T bit_unpacking_s_ct;           /* '<S170>/bit_unpacking_s' */
  real_T bit_unpacking_s_fz;           /* '<S171>/bit_unpacking_s' */
  real_T bit_unpacking_s_hs;           /* '<S172>/bit_unpacking_s' */
  real_T staten;                       /* '<Root>/State_of_the_Cart' */
  uint32_T IO_CAN_ReadMsg_s_o2[2];     /* '<S90>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5;        /* '<S90>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_k[2];   /* '<S96>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_c;      /* '<S96>/IO_CAN_ReadMsg_s' */
  uint32_T ADC_Get_s_o2;               /* '<S60>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_a;             /* '<S62>/ADC_Get_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_h[2];   /* '<S64>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_a;      /* '<S64>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_ku[2];  /* '<S77>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_e;      /* '<S77>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_g[2];   /* '<S257>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_f;      /* '<S257>/IO_CAN_ReadMsg_s' */
  uint32_T ADC_Get_s_o2_k;             /* '<S295>/ADC_Get_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_k5[2];  /* '<S253>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_g;      /* '<S253>/IO_CAN_ReadMsg_s' */
  uint32_T ADC_Get_s_o2_n;             /* '<S141>/ADC_Get_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_a[2];   /* '<S224>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_d;      /* '<S224>/IO_CAN_ReadMsg_s' */
  uint32_T bit_packing_s[2];           /* '<S103>/bit_packing_s' */
  uint32_T bit_packing_s_h[2];         /* '<S104>/bit_packing_s' */
  uint32_T bit_packing_s_e[2];         /* '<S105>/bit_packing_s' */
  uint32_T bit_packing_s_g[2];         /* '<S106>/bit_packing_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_i[2];   /* '<S120>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_l;      /* '<S120>/IO_CAN_ReadMsg_s' */
  uint32_T bit_packing_s_c[2];         /* '<S107>/bit_packing_s' */
  uint32_T bit_packing_s_d[2];         /* '<S108>/bit_packing_s' */
  uint32_T bit_packing_s_dm[2];        /* '<S109>/bit_packing_s' */
  uint32_T OR_TX[2];                   /* '<S9>/OR_TX' */
  uint32_T bit_packing_s_f[2];         /* '<S112>/bit_packing_s' */
  uint32_T bit_packing_s_l[2];         /* '<S113>/bit_packing_s' */
  uint32_T bit_packing_s_m[2];         /* '<S114>/bit_packing_s' */
  uint32_T bit_packing_s_o[2];         /* '<S115>/bit_packing_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_hx[2];  /* '<S129>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_b;      /* '<S129>/IO_CAN_ReadMsg_s' */
  uint32_T bit_packing_s_j[2];         /* '<S116>/bit_packing_s' */
  uint32_T bit_packing_s_du[2];        /* '<S117>/bit_packing_s' */
  uint32_T bit_packing_s_p[2];         /* '<S118>/bit_packing_s' */
  uint32_T OR_TX_a[2];                 /* '<S10>/OR_TX' */
  uint32_T bit_packing_s_hd[2];        /* '<S189>/bit_packing_s' */
  uint32_T bit_packing_s_p4[2];        /* '<S190>/bit_packing_s' */
  uint32_T bit_packing_s_fv[2];        /* '<S191>/bit_packing_s' */
  uint32_T bit_packing_s_fy[2];        /* '<S192>/bit_packing_s' */
  uint32_T bit_packing_s_i[2];         /* '<S193>/bit_packing_s' */
  uint32_T bit_packing_s_om[2];        /* '<S194>/bit_packing_s' */
  uint32_T bit_packing_s_a[2];         /* '<S195>/bit_packing_s' */
  uint32_T OR_TX_d[2];                 /* '<S21>/OR_TX' */
  uint32_T Product10;                  /* '<Root>/Product10' */
  uint32_T bit_packing_s_es[2];        /* '<S198>/bit_packing_s' */
  uint32_T bit_packing_s_pz[2];        /* '<S199>/bit_packing_s' */
  uint32_T bit_packing_s_ce[2];        /* '<S200>/bit_packing_s' */
  uint32_T bit_packing_s_k[2];         /* '<S201>/bit_packing_s' */
  uint32_T OR_TX_l[2];                 /* '<S22>/OR_TX' */
  uint32_T bit_packing_s_jr[2];        /* '<S325>/bit_packing_s' */
  uint32_T bit_packing_s_ch[2];        /* '<S326>/bit_packing_s' */
  uint32_T bit_packing_s_gi[2];        /* '<S327>/bit_packing_s' */
  uint32_T bit_packing_s_lu[2];        /* '<S328>/bit_packing_s' */
  uint32_T OR_TX_f[2];                 /* '<S52>/OR_TX' */
  uint32_T ADC_Get_s_o2_h;             /* '<S304>/ADC_Get_s' */
  uint32_T bit_packing_s_hf[2];        /* '<S139>/bit_packing_s' */
  uint32_T ADC_Get_s_o2_p;             /* '<S58>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_i;             /* '<S301>/ADC_Get_s' */
  uint32_T bit_packing_s_ax[2];        /* '<S183>/bit_packing_s' */
  uint32_T bit_packing_s_mz[2];        /* '<S184>/bit_packing_s' */
  uint32_T OR_TX_n[2];                 /* '<S155>/OR_TX' */
  uint32_T IO_CAN_ReadMsg_s_o2_d[2];   /* '<S158>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_m;      /* '<S158>/IO_CAN_ReadMsg_s' */
  uint32_T TmpSignalConversionAtIO_CAN_Wri[2];
  uint32_T bit_packing_s_b[2];         /* '<S175>/bit_packing_s' */
  uint32_T bit_packing_s_dv[2];        /* '<S176>/bit_packing_s' */
  uint32_T OR_TX_lp[2];                /* '<S153>/OR_TX' */
  uint32_T IO_CAN_ReadMsg_s_o2_e[2];   /* '<S161>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_f2;     /* '<S161>/IO_CAN_ReadMsg_s' */
  uint32_T bit_packing_s_oo[2];        /* '<S179>/bit_packing_s' */
  uint32_T bit_packing_s_la[2];        /* '<S180>/bit_packing_s' */
  uint32_T OR_TX_j[2];                 /* '<S154>/OR_TX' */
  uint32_T IO_CAN_ReadMsg_s_o2_m[2];   /* '<S165>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_ca;     /* '<S165>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_f[2];   /* '<S169>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_gl;     /* '<S169>/IO_CAN_ReadMsg_s' */
  uint32_T ADC_Get_s_o2_e;             /* '<S214>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_o;             /* '<S216>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_ek;            /* '<S218>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_j;             /* '<S220>/ADC_Get_s' */
  uint32_T ADC_Get_s_o2_hn;            /* '<S222>/ADC_Get_s' */
  uint32_T MainDlg_basic_s_o2;         /* '<S251>/MainDlg_basic_s' */
  uint32_T IO_PWD_ComplexGet_s_o2;     /* '<S296>/IO_PWD_ComplexGet_s' */
  uint32_T IO_PWD_ComplexGet_s_o3;     /* '<S296>/IO_PWD_ComplexGet_s' */
  uint32_T IO_PWD_ComplexGet_s_o2_h;   /* '<S298>/IO_PWD_ComplexGet_s' */
  uint32_T IO_PWD_ComplexGet_s_o3_h;   /* '<S298>/IO_PWD_ComplexGet_s' */
  uint32_T IO_CAN_ReadMsg_s_o2_n[2];   /* '<S384>/IO_CAN_ReadMsg_s' */
  uint32_T IO_CAN_ReadMsg_s_o5_i;      /* '<S384>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1;      /* '<S89>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2;      /* '<S89>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1;        /* '<S90>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_d;    /* '<S95>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_f;    /* '<S95>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_h;      /* '<S96>/IO_CAN_ReadMsg_s' */
  uint16_T ADC_Get_s_o1;               /* '<S60>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s;          /* '<S59>/ADC_ChannelInit_s' */
  uint16_T ADC_Get_s_o1_n;             /* '<S62>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_f;        /* '<S61>/ADC_ChannelInit_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_o;    /* '<S63>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_a;    /* '<S63>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_c;      /* '<S64>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_m;    /* '<S76>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_j;    /* '<S76>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_j;      /* '<S77>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_md;   /* '<S101>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_b;    /* '<S101>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_p;    /* '<S256>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_k;    /* '<S256>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_g;      /* '<S257>/IO_CAN_ReadMsg_s' */
  uint16_T ADC_Get_s_o1_l;             /* '<S295>/ADC_Get_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_dr;   /* '<S252>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_g;    /* '<S252>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_m;      /* '<S253>/IO_CAN_ReadMsg_s' */
  uint16_T ADC_Get_s_o1_o;             /* '<S141>/ADC_Get_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_d0;   /* '<S223>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_n;    /* '<S223>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_f;      /* '<S224>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_g;    /* '<S119>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_p;    /* '<S119>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_a;      /* '<S120>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_WriteMsg_s;          /* '<S102>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_gc;   /* '<S110>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_c;    /* '<S110>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_px;   /* '<S128>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_kh;   /* '<S128>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_a5;     /* '<S129>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_k;        /* '<S111>/IO_CAN_WriteMsg_s' */
  uint16_T ADC_ChannelInit_s_j;        /* '<S140>/ADC_ChannelInit_s' */
  uint16_T POWER_Set_Init_s;           /* '<S142>/POWER_Set_Init_s' */
  uint16_T IO_DO_Set_s;                /* '<S147>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1;      /* '<S144>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2;      /* '<S144>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1;          /* '<S143>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2;          /* '<S143>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s;               /* '<S145>/IO_DO_Init_s' */
  uint16_T DataTypeConversion7;        /* '<Root>/Data Type Conversion7' */
  uint16_T DataTypeConversion8;        /* '<Root>/Data Type Conversion8' */
  uint16_T IO_CAN_ConfigMsg_s_o1_h;    /* '<S187>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_n4;   /* '<S187>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_a;        /* '<S188>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_ph;   /* '<S196>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_f1;   /* '<S196>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_p;        /* '<S197>/IO_CAN_WriteMsg_s' */
  uint16_T IO_PWM_SetDuty_s_o1;        /* '<S234>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o2;        /* '<S234>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o3;        /* '<S234>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_GetCur_s_o1;         /* '<S231>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_GetCur_s_o2;         /* '<S231>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_Init_s;              /* '<S232>/IO_PWM_Init_s' */
  uint16_T IO_PWM_SetDuty_s_o1_c;      /* '<S239>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o2_j;      /* '<S239>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o3_n;      /* '<S239>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_GetCur_s_o1_o;       /* '<S236>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_GetCur_s_o2_o;       /* '<S236>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_Init_s_o;            /* '<S237>/IO_PWM_Init_s' */
  uint16_T IO_PWM_SetDuty_s_o1_p;      /* '<S244>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o2_f;      /* '<S244>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o3_na;     /* '<S244>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_GetCur_s_o1_f;       /* '<S241>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_GetCur_s_o2_k;       /* '<S241>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_Init_s_n;            /* '<S242>/IO_PWM_Init_s' */
  uint16_T IO_PWM_SetDuty_s_o1_l;      /* '<S249>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o2_l;      /* '<S249>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_SetDuty_s_o3_d;      /* '<S249>/IO_PWM_SetDuty_s' */
  uint16_T IO_PWM_GetCur_s_o1_k;       /* '<S246>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_GetCur_s_o2_i;       /* '<S246>/IO_PWM_GetCur_s' */
  uint16_T IO_PWM_Init_s_i;            /* '<S247>/IO_PWM_Init_s' */
  uint16_T IO_DO_Set_s_p;              /* '<S286>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_d;    /* '<S283>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_j;    /* '<S283>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_g;        /* '<S282>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_c;        /* '<S282>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_m;             /* '<S284>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_b;              /* '<S292>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_g;    /* '<S289>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_a;    /* '<S289>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_d;        /* '<S288>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_l;        /* '<S288>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_l;             /* '<S290>/IO_DO_Init_s' */
  uint16_T ADC_ChannelInit_s_a;        /* '<S294>/ADC_ChannelInit_s' */
  uint16_T IO_DO_Set_s_n;              /* '<S315>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_k;    /* '<S312>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_c;    /* '<S312>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_gb;       /* '<S311>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_g;        /* '<S311>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_j;             /* '<S313>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_k;              /* '<S321>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_l;    /* '<S318>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_k;    /* '<S318>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_o;        /* '<S317>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_h;        /* '<S317>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_p;             /* '<S319>/IO_DO_Init_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_c;    /* '<S323>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_h;    /* '<S323>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_j;        /* '<S324>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_i;    /* '<S337>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_hc;   /* '<S337>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_k;    /* '<S137>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_e;    /* '<S137>/IO_CAN_ConfigMsg_s' */
  uint16_T ADC_Get_s_o1_k;             /* '<S304>/ADC_Get_s' */
  uint16_T IO_CAN_WriteMsg_s_o;        /* '<S138>/IO_CAN_WriteMsg_s' */
  uint16_T ADC_ChannelInit_s_l;        /* '<S303>/ADC_ChannelInit_s' */
  uint16_T ADC_Get_s_o1_a;             /* '<S58>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_b;        /* '<S57>/ADC_ChannelInit_s' */
  uint16_T IO_POWER_Set_s;             /* '<S278>/IO_POWER_Set_s' */
  uint16_T IO_POWER_Set_s_e;           /* '<S279>/IO_POWER_Set_s' */
  uint16_T IO_POWER_Set_s_f;           /* '<S280>/IO_POWER_Set_s' */
  uint16_T IO_POWER_Set_s_o;           /* '<S281>/IO_POWER_Set_s' */
  uint16_T IO_DO_Set_s_h;              /* '<S309>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_gn;   /* '<S306>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_g;    /* '<S306>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_c;        /* '<S305>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_d;        /* '<S305>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_c;             /* '<S307>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_d;              /* '<S276>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_n;    /* '<S273>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_gt;   /* '<S273>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_i;        /* '<S272>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_b;        /* '<S272>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_p5;            /* '<S274>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_i;              /* '<S264>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_dy;   /* '<S261>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_d;    /* '<S261>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_ch;       /* '<S260>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_n;        /* '<S260>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_o;             /* '<S262>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_g;              /* '<S270>/IO_DO_Set_s' */
  uint16_T IO_DO_GetVoltage_s_o1_c;    /* '<S267>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetVoltage_s_o2_b;    /* '<S267>/IO_DO_GetVoltage_s' */
  uint16_T IO_DO_GetCur_s_o1_l;        /* '<S266>/IO_DO_GetCur_s' */
  uint16_T IO_DO_GetCur_s_o2_e;        /* '<S266>/IO_DO_GetCur_s' */
  uint16_T IO_DO_Init_s_c5;            /* '<S268>/IO_DO_Init_s' */
  uint16_T ADC_Get_s_o1_p;             /* '<S301>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_i;        /* '<S300>/ADC_ChannelInit_s' */
  uint16_T IO_DO_Set_s_c;              /* '<S331>/IO_DO_Set_s' */
  uint16_T IO_DO_Init_s_lc;            /* '<S329>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_cd;             /* '<S335>/IO_DO_Set_s' */
  uint16_T IO_DO_Init_s_b;             /* '<S333>/IO_DO_Init_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_kp;   /* '<S181>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_d;    /* '<S181>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_m;        /* '<S182>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_b;    /* '<S157>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_ke;   /* '<S157>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_gg;     /* '<S158>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_ba;   /* '<S185>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_cn;   /* '<S185>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_l;        /* '<S186>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_pt;   /* '<S173>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_o;    /* '<S173>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_d;        /* '<S174>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_n;    /* '<S160>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_eu;   /* '<S160>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_l;      /* '<S161>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_g2;   /* '<S177>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_pn;   /* '<S177>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_WriteMsg_s_o5;       /* '<S178>/IO_CAN_WriteMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_kl;   /* '<S164>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_dp;   /* '<S164>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_k;      /* '<S165>/IO_CAN_ReadMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o1_ka;   /* '<S168>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ConfigMsg_s_o2_m;    /* '<S168>/IO_CAN_ConfigMsg_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_hm;     /* '<S169>/IO_CAN_ReadMsg_s' */
  uint16_T ADC_Get_s_o1_av;            /* '<S214>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_e;        /* '<S213>/ADC_ChannelInit_s' */
  uint16_T IO_DO_Set_s_m;              /* '<S207>/IO_DO_Set_s' */
  uint16_T IO_DO_Init_s_c4;            /* '<S205>/IO_DO_Init_s' */
  uint16_T IO_DO_Set_s_f;              /* '<S211>/IO_DO_Set_s' */
  uint16_T IO_DO_Init_s_i;             /* '<S209>/IO_DO_Init_s' */
  uint16_T ADC_Get_s_o1_d;             /* '<S216>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_m;        /* '<S215>/ADC_ChannelInit_s' */
  uint16_T ADC_Get_s_o1_c;             /* '<S218>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_id;       /* '<S217>/ADC_ChannelInit_s' */
  uint16_T ADC_Get_s_o1_lw;            /* '<S220>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_i1;       /* '<S219>/ADC_ChannelInit_s' */
  uint16_T ADC_Get_s_o1_cg;            /* '<S222>/ADC_Get_s' */
  uint16_T ADC_ChannelInit_s_lh;       /* '<S221>/ADC_ChannelInit_s' */
  uint16_T MainDlg_basic_s_o1;         /* '<S251>/MainDlg_basic_s' */
  uint16_T IO_PWD_ComplexGet_s_o1;     /* '<S296>/IO_PWD_ComplexGet_s' */
  uint16_T PWD_ComplexInit_s;          /* '<S297>/PWD_ComplexInit_s' */
  uint16_T IO_PWD_ComplexGet_s_o1_d;   /* '<S298>/IO_PWD_ComplexGet_s' */
  uint16_T PWD_ComplexInit_s_p;        /* '<S299>/PWD_ComplexInit_s' */
  uint16_T IO_CAN_ReadMsg_s_o1_p;      /* '<S384>/IO_CAN_ReadMsg_s' */
  uint16_T IO_DO_ResetProtection_s_o1; /* '<S334>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_g;/* '<S330>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_i;/* '<S320>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_f;/* '<S314>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_gf;/* '<S308>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_a;/* '<S291>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_o;/* '<S285>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_p;/* '<S275>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_pm;/* '<S269>/IO_DO_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_l;/* '<S263>/IO_DO_ResetProtection_s' */
  uint16_T IO_PWM_ResetProtection_s_o1;/* '<S248>/IO_PWM_ResetProtection_s' */
  uint16_T IO_PWM_ResetProtection_s_o1_c;/* '<S243>/IO_PWM_ResetProtection_s' */
  uint16_T IO_PWM_ResetProtection_s_o1_b;/* '<S238>/IO_PWM_ResetProtection_s' */
  uint16_T IO_PWM_ResetProtection_s_o1_e;/* '<S233>/IO_PWM_ResetProtection_s' */
  uint16_T IO_DO_ResetProtection_s_o1_h;/* '<S146>/IO_DO_ResetProtection_s' */
  uint8_T IO_CAN_ReadMsg_s_o3;         /* '<S90>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4;         /* '<S90>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_o;       /* '<S96>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_d;       /* '<S96>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_n;       /* '<S64>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_j;       /* '<S64>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_f;       /* '<S77>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_l;       /* '<S77>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_l;       /* '<S257>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_b;       /* '<S257>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_ob;      /* '<S253>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_o;       /* '<S253>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_lg;      /* '<S224>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_li;      /* '<S224>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_i;       /* '<S120>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_k;       /* '<S120>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_lj;      /* '<S129>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_n;       /* '<S129>/IO_CAN_ReadMsg_s' */
  uint8_T DataTypeConversion;          /* '<S39>/Data Type Conversion' */
  uint8_T IO_CAN_ReadMsg_s_o3_h;       /* '<S158>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_oa;      /* '<S158>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_iu;      /* '<S161>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_f;       /* '<S161>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_lk;      /* '<S165>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_dw;      /* '<S165>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_g;       /* '<S169>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_dp;      /* '<S169>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o3_ho;      /* '<S384>/IO_CAN_ReadMsg_s' */
  uint8_T IO_CAN_ReadMsg_s_o4_a;       /* '<S384>/IO_CAN_ReadMsg_s' */
  uint8_T IO_DO_ResetProtection_s_o2;  /* '<S334>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_p;/* '<S330>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_m;/* '<S320>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_c;/* '<S314>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_cu;/* '<S308>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_n;/* '<S291>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_o;/* '<S285>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_d;/* '<S275>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_e;/* '<S269>/IO_DO_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_o2;/* '<S263>/IO_DO_ResetProtection_s' */
  uint8_T IO_PWM_ResetProtection_s_o2; /* '<S248>/IO_PWM_ResetProtection_s' */
  uint8_T IO_PWM_ResetProtection_s_o2_o;/* '<S243>/IO_PWM_ResetProtection_s' */
  uint8_T IO_PWM_ResetProtection_s_o2_k;/* '<S238>/IO_PWM_ResetProtection_s' */
  uint8_T IO_PWM_ResetProtection_s_o2_f;/* '<S233>/IO_PWM_ResetProtection_s' */
  uint8_T IO_DO_ResetProtection_s_o2_mg;/* '<S146>/IO_DO_ResetProtection_s' */
  boolean_T ADC_Get_s_o3;              /* '<S60>/ADC_Get_s' */
  boolean_T ADC_Get_s_o3_g;            /* '<S62>/ADC_Get_s' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
  boolean_T ADC_Get_s_o3_p;            /* '<S295>/ADC_Get_s' */
  boolean_T ADC_Get_s_o3_j;            /* '<S141>/ADC_Get_s' */
  boolean_T LogicalOperator_k;         /* '<S55>/Logical Operator' */
  boolean_T LogicalOperator_m;         /* '<Root>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<Root>/Logical Operator1' */
  boolean_T GreaterThan;               /* '<S18>/GreaterThan' */
  boolean_T compare2error_s;           /* '<S148>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3;     /* '<S144>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3;         /* '<S143>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_i;         /* '<S235>/compare2error_s' */
  boolean_T IO_PWM_GetCur_s_o3;        /* '<S231>/IO_PWM_GetCur_s' */
  boolean_T compare2error_s_k;         /* '<S240>/compare2error_s' */
  boolean_T IO_PWM_GetCur_s_o3_f;      /* '<S236>/IO_PWM_GetCur_s' */
  boolean_T compare2error_s_j;         /* '<S245>/compare2error_s' */
  boolean_T IO_PWM_GetCur_s_o3_d;      /* '<S241>/IO_PWM_GetCur_s' */
  boolean_T compare2error_s_g;         /* '<S250>/compare2error_s' */
  boolean_T IO_PWM_GetCur_s_o3_l;      /* '<S246>/IO_PWM_GetCur_s' */
  boolean_T compare2error_s_e;         /* '<S287>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_d;   /* '<S283>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_f;       /* '<S282>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_c;         /* '<S293>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_o;   /* '<S289>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_o;       /* '<S288>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_n;         /* '<S316>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_dj;  /* '<S312>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_c;       /* '<S311>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_a;         /* '<S322>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_p;   /* '<S318>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_k;       /* '<S317>/IO_DO_GetCur_s' */
  boolean_T ADC_Get_s_o3_k;            /* '<S304>/ADC_Get_s' */
  boolean_T RelationalOperator3;       /* '<Root>/Relational Operator3' */
  boolean_T ADC_Get_s_o3_h;            /* '<S58>/ADC_Get_s' */
  boolean_T compare2error_s_kb;        /* '<S310>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_l;   /* '<S306>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_e;       /* '<S305>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_o;         /* '<S277>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_n;   /* '<S273>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_b;       /* '<S272>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_oz;        /* '<S265>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_j;   /* '<S261>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_eb;      /* '<S260>/IO_DO_GetCur_s' */
  boolean_T compare2error_s_cy;        /* '<S271>/compare2error_s' */
  boolean_T IO_DO_GetVoltage_s_o3_f;   /* '<S267>/IO_DO_GetVoltage_s' */
  boolean_T IO_DO_GetCur_s_o3_os;      /* '<S266>/IO_DO_GetCur_s' */
  boolean_T ADC_Get_s_o3_d;            /* '<S301>/ADC_Get_s' */
  boolean_T RelationalOperator1;       /* '<Root>/Relational Operator1' */
  boolean_T compare2error_s_ed;        /* '<S332>/compare2error_s' */
  boolean_T compare2error_s_kh;        /* '<S336>/compare2error_s' */
  boolean_T ADC_Get_s_o3_n;            /* '<S214>/ADC_Get_s' */
  boolean_T compare2error_s_og;        /* '<S208>/compare2error_s' */
  boolean_T compare2error_s_p;         /* '<S212>/compare2error_s' */
  boolean_T ADC_Get_s_o3_o;            /* '<S216>/ADC_Get_s' */
  boolean_T ADC_Get_s_o3_nf;           /* '<S218>/ADC_Get_s' */
  boolean_T ADC_Get_s_o3_e;            /* '<S220>/ADC_Get_s' */
  boolean_T ADC_Get_s_o3_pk;           /* '<S222>/ADC_Get_s' */
  boolean_T RTDLED;                    /* '<Root>/State_of_the_Cart' */
  boolean_T inv_on1;                   /* '<Root>/State_of_the_Cart' */
  boolean_T enable1;                   /* '<Root>/State_of_the_Cart' */
  boolean_T inv_on2;                   /* '<Root>/State_of_the_Cart' */
  boolean_T enable2;                   /* '<Root>/State_of_the_Cart' */
  boolean_T MCR;                       /* '<Root>/State_of_the_Cart' */
  boolean_T DC_on;                     /* '<Root>/State_of_the_Cart' */
  boolean_T erdel2;                    /* '<Root>/State_of_the_Cart' */
  boolean_T erdel1;                    /* '<Root>/State_of_the_Cart' */
  boolean_T RTDSGR;                    /* '<Root>/State_of_the_Cart' */
  boolean_T action;                    /* '<Root>/State_of_the_Cart' */
  rtB_IO_DO_ResetProtection_flash IO_DO_ResetProtection_f;/* '<S203>/IO_DO_ResetProtection' */
  rtB_IO_DO_ResetProtection_flash IO_DO_ResetProtection_o;/* '<S202>/IO_DO_ResetProtection' */
} BlockIO_flashHaileyECUv001;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i2;         /* '<Root>/State_of_the_Cart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T Output_DSTATE;               /* '<S386>/Output' */
  uint8_T is_c2_flashHaileyECUv001;    /* '<S47>/action chart' */
  uint8_T is_active_c2_flashHaileyECUv001;/* '<S47>/action chart' */
  uint8_T is_c1_flashHaileyECUv001;    /* '<Root>/State_of_the_Cart' */
  uint8_T is_ok;                       /* '<Root>/State_of_the_Cart' */
  uint8_T is_AMK_start;                /* '<Root>/State_of_the_Cart' */
  uint8_T is_active_c1_flashHaileyECUv001;/* '<Root>/State_of_the_Cart' */
  uint8_T temporalCounter_i1_b;        /* '<Root>/State_of_the_Cart' */
  uint8_T is_c3_flashHaileyECUv001;    /* '<Root>/Chart' */
  uint8_T is_active_c3_flashHaileyECUv001;/* '<Root>/Chart' */
  boolean_T rtr;                       /* '<Root>/State_of_the_Cart' */
  boolean_T amkkk;                     /* '<Root>/State_of_the_Cart' */
} D_Work_flashHaileyECUv001;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState IO_DO_ResetProtection_Trig_ZCE;/* '<S54>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_l;/* '<S53>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_m;/* '<S51>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_n;/* '<S50>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_i;/* '<S49>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_g;/* '<S41>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_j;/* '<S40>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_k;/* '<S38>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_p;/* '<S37>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_Z_nn;/* '<S36>/IO_DO_ResetProtection' */
  ZCSigState IO_PWM_ResetProtection_Trig_ZCE;/* '<S32>/IO_PWM_ResetProtection' */
  ZCSigState IO_PWM_ResetProtection_Trig_Z_k;/* '<S31>/IO_PWM_ResetProtection' */
  ZCSigState IO_PWM_ResetProtection_Trig_Z_g;/* '<S30>/IO_PWM_ResetProtection' */
  ZCSigState IO_PWM_ResetProtection_Trig_Z_f;/* '<S29>/IO_PWM_ResetProtection' */
  rtZCE_IO_DO_ResetProtection_fla IO_DO_ResetProtection_f;/* '<S203>/IO_DO_ResetProtection' */
  rtZCE_IO_DO_ResetProtection_fla IO_DO_ResetProtection_o;/* '<S202>/IO_DO_ResetProtection' */
  ZCSigState IO_DO_ResetProtection_Trig_ZC_a;/* '<S17>/IO_DO_ResetProtection' */
} PrevZCSigStates_flashHaileyECUv;

/* Parameters (default storage) */
struct Parameters_flashHaileyECUv001_ {
  uint8_T Trigger_Block_trigger_offset;
                                 /* Mask Parameter: Trigger_Block_trigger_offset
                                  * Referenced by: '<S385>/Constant'
                                  */
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S388>/FixPt Switch'
                                        */
  real_T deltay1_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/deltay1'
                                        */
  real_T u00Value1_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/100%Value 1'
                                        */
  real_T uValue1_Value;                /* Expression: 35
                                        * Referenced by: '<Root>/0%Value 1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T deltay2_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/deltay2'
                                        */
  real_T u00Value2_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/100%Value 2'
                                        */
  real_T uValue2_Value;                /* Expression: 35
                                        * Referenced by: '<Root>/0%Value 2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T u_Value;                      /* Expression: 0
                                        * Referenced by: '<S4>/1'
                                        */
  real_T deltay2_Value_j;              /* Expression: 100
                                        * Referenced by: '<S14>/deltay2'
                                        */
  real_T u00Value2_Value_d;            /* Expression: 7080
                                        * Referenced by: '<S14>/100%Value 2'
                                        */
  real_T uValue2_Value_h;              /* Expression: 7800
                                        * Referenced by: '<S14>/0%Value 2'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 100
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_o;       /* Expression: 0
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Constant11_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T deltay1_Value_c;              /* Expression: 100
                                        * Referenced by: '<S14>/deltay1'
                                        */
  real_T u00Value1_Value_p;            /* Expression: 9271
                                        * Referenced by: '<S14>/100%Value 1'
                                        */
  real_T uValue1_Value_b;              /* Expression: 8570
                                        * Referenced by: '<S14>/0%Value 1'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 100
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T revomax_Value;                /* Expression: 4000
                                        * Referenced by: '<Root>/revomax'
                                        */
  real_T mommax_Value;                 /* Expression: 1000
                                        * Referenced by: '<Root>/mommax'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T dASGCheck_Value;              /* Expression: 10
                                        * Referenced by: '<S14>/dASGCheck'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S47>/Zero'
                                        */
  real_T br_light_border_Value;        /* Expression: 650
                                        * Referenced by: '<S18>/br_light_border'
                                        */
  real_T Constant25_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant25'
                                        */
  real_T Constant24_Value;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant24'
                                        */
  uint32_T id_TX_Value;                /* Computed Parameter: id_TX_Value
                                        * Referenced by: '<S9>/id_TX'
                                        */
  uint32_T id_TX_Value_p;              /* Computed Parameter: id_TX_Value_p
                                        * Referenced by: '<S10>/id_TX'
                                        */
  uint32_T id_TX_Value_n;              /* Computed Parameter: id_TX_Value_n
                                        * Referenced by: '<S21>/id_TX'
                                        */
  uint32_T id_TX_Value_c;              /* Computed Parameter: id_TX_Value_c
                                        * Referenced by: '<S22>/id_TX'
                                        */
  uint32_T id_TX_Value_b;              /* Computed Parameter: id_TX_Value_b
                                        * Referenced by: '<S52>/id_TX'
                                        */
  uint32_T id_TX_Value_i;              /* Computed Parameter: id_TX_Value_i
                                        * Referenced by: '<S15>/id_TX'
                                        */
  uint32_T id_TX_Value_d;              /* Computed Parameter: id_TX_Value_d
                                        * Referenced by: '<S155>/id_TX'
                                        */
  uint32_T id_TX_Value_o;              /* Computed Parameter: id_TX_Value_o
                                        * Referenced by: '<S156>/id_TX'
                                        */
  uint32_T id_TX_Value_g;              /* Computed Parameter: id_TX_Value_g
                                        * Referenced by: '<S153>/id_TX'
                                        */
  uint32_T id_TX_Value_ok;             /* Computed Parameter: id_TX_Value_ok
                                        * Referenced by: '<S154>/id_TX'
                                        */
  uint16_T u00Lfter_Value;             /* Computed Parameter: u00Lfter_Value
                                        * Referenced by: '<Root>/100%Lüfter'
                                        */
  uint16_T u6Lfter_Value;              /* Computed Parameter: u6Lfter_Value
                                        * Referenced by: '<Root>/76% Lüfter'
                                        */
  uint16_T u00Lfter1_Value;            /* Computed Parameter: u00Lfter1_Value
                                        * Referenced by: '<Root>/100%Lüfter1'
                                        */
  uint16_T u6Lfter1_Value;             /* Computed Parameter: u6Lfter1_Value
                                        * Referenced by: '<Root>/76% Lüfter1'
                                        */
  uint16_T u00Lfter2_Value;            /* Computed Parameter: u00Lfter2_Value
                                        * Referenced by: '<Root>/100%Lüfter2'
                                        */
  uint16_T Constant23_Value;           /* Computed Parameter: Constant23_Value
                                        * Referenced by: '<Root>/Constant23'
                                        */
  uint16_T Constant27_Value;           /* Computed Parameter: Constant27_Value
                                        * Referenced by: '<Root>/Constant27'
                                        */
  uint16_T Constant28_Value;           /* Computed Parameter: Constant28_Value
                                        * Referenced by: '<Root>/Constant28'
                                        */
  boolean_T Constant21_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant21'
                                        */
  boolean_T Constant2_Value;           /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S13>/Constant2'
                                        */
  boolean_T Constant20_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant20'
                                        */
  boolean_T Constant13_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant13'
                                        */
  boolean_T Constant14_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant14'
                                        */
  boolean_T Constant15_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant15'
                                        */
  boolean_T Constant18_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant18'
                                        */
  uint8_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S388>/Constant'
                                        */
  uint8_T length_TX_Value;             /* Computed Parameter: length_TX_Value
                                        * Referenced by: '<S9>/length_TX'
                                        */
  uint8_T id_format_TX_Value;          /* Computed Parameter: id_format_TX_Value
                                        * Referenced by: '<S9>/id_format_TX'
                                        */
  uint8_T length_TX_Value_h;           /* Computed Parameter: length_TX_Value_h
                                        * Referenced by: '<S10>/length_TX'
                                        */
  uint8_T id_format_TX_Value_l;      /* Computed Parameter: id_format_TX_Value_l
                                      * Referenced by: '<S10>/id_format_TX'
                                      */
  uint8_T length_TX_Value_i;           /* Computed Parameter: length_TX_Value_i
                                        * Referenced by: '<S21>/length_TX'
                                        */
  uint8_T id_format_TX_Value_o;      /* Computed Parameter: id_format_TX_Value_o
                                      * Referenced by: '<S21>/id_format_TX'
                                      */
  uint8_T length_TX_Value_o;           /* Computed Parameter: length_TX_Value_o
                                        * Referenced by: '<S22>/length_TX'
                                        */
  uint8_T id_format_TX_Value_l0;    /* Computed Parameter: id_format_TX_Value_l0
                                     * Referenced by: '<S22>/id_format_TX'
                                     */
  uint8_T length_TX_Value_n;           /* Computed Parameter: length_TX_Value_n
                                        * Referenced by: '<S52>/length_TX'
                                        */
  uint8_T id_format_TX_Value_h;      /* Computed Parameter: id_format_TX_Value_h
                                      * Referenced by: '<S52>/id_format_TX'
                                      */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S386>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S387>/FixPt Constant'
                                       */
  uint8_T length_TX_Value_os;          /* Computed Parameter: length_TX_Value_os
                                        * Referenced by: '<S15>/length_TX'
                                        */
  uint8_T id_format_TX_Value_e;      /* Computed Parameter: id_format_TX_Value_e
                                      * Referenced by: '<S15>/id_format_TX'
                                      */
  uint8_T length_TX_Value_o4;          /* Computed Parameter: length_TX_Value_o4
                                        * Referenced by: '<S155>/length_TX'
                                        */
  uint8_T id_format_TX_Value_m;      /* Computed Parameter: id_format_TX_Value_m
                                      * Referenced by: '<S155>/id_format_TX'
                                      */
  uint8_T length_TX_Value_a;           /* Computed Parameter: length_TX_Value_a
                                        * Referenced by: '<S156>/length_TX'
                                        */
  uint8_T id_format_TX_Value_l2;    /* Computed Parameter: id_format_TX_Value_l2
                                     * Referenced by: '<S156>/id_format_TX'
                                     */
  uint8_T length_TX_Value_k;           /* Computed Parameter: length_TX_Value_k
                                        * Referenced by: '<S153>/length_TX'
                                        */
  uint8_T id_format_TX_Value_hf;    /* Computed Parameter: id_format_TX_Value_hf
                                     * Referenced by: '<S153>/id_format_TX'
                                     */
  uint8_T length_TX_Value_nv;          /* Computed Parameter: length_TX_Value_nv
                                        * Referenced by: '<S154>/length_TX'
                                        */
  uint8_T id_format_TX_Value_i;      /* Computed Parameter: id_format_TX_Value_i
                                      * Referenced by: '<S154>/id_format_TX'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_flashHaileyECUv001 {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_flashHaileyECUv001 flashHaileyECUv001_P;

/* Block signals (default storage) */
extern BlockIO_flashHaileyECUv001 flashHaileyECUv001_B;

/* Block states (default storage) */
extern D_Work_flashHaileyECUv001 flashHaileyECUv001_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_flashHaileyECUv flashHaileyECUv0_PrevZCSigState;

/* Model entry point functions */
extern void flashHaileyECUv001_initialize(void);
extern void flashHaileyECUv001_step(void);
extern void flashHaileyECUv001_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flashHaileyECUv001 *const flashHaileyECUv001_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flashHaileyECUv001'
 * '<S1>'   : 'flashHaileyECUv001/ADC_UBAT3'
 * '<S2>'   : 'flashHaileyECUv001/ADC_UBAT5'
 * '<S3>'   : 'flashHaileyECUv001/ADC_UBAT6'
 * '<S4>'   : 'flashHaileyECUv001/AMKFehlerSammler'
 * '<S5>'   : 'flashHaileyECUv001/AMK_Actual_Values1_1'
 * '<S6>'   : 'flashHaileyECUv001/AMK_Actual_Values1_2'
 * '<S7>'   : 'flashHaileyECUv001/AMK_Actual_Values2_3'
 * '<S8>'   : 'flashHaileyECUv001/AMK_Actual_Values2_4'
 * '<S9>'   : 'flashHaileyECUv001/AMK_Setpoints_1'
 * '<S10>'  : 'flashHaileyECUv001/AMK_Setpoints_2'
 * '<S11>'  : 'flashHaileyECUv001/AMK_Setpoints_3'
 * '<S12>'  : 'flashHaileyECUv001/AMK_Setpoints_4'
 * '<S13>'  : 'flashHaileyECUv001/AMS_err1_1'
 * '<S14>'  : 'flashHaileyECUv001/APPS'
 * '<S15>'  : 'flashHaileyECUv001/AkkuControl'
 * '<S16>'  : 'flashHaileyECUv001/Bremsdrucksensor'
 * '<S17>'  : 'flashHaileyECUv001/Bremslicht'
 * '<S18>'  : 'flashHaileyECUv001/Bremslichtsteuerung'
 * '<S19>'  : 'flashHaileyECUv001/Chart'
 * '<S20>'  : 'flashHaileyECUv001/DV-Lenkung'
 * '<S21>'  : 'flashHaileyECUv001/Debugmess1'
 * '<S22>'  : 'flashHaileyECUv001/Debugmess2'
 * '<S23>'  : 'flashHaileyECUv001/EBS Control Unit'
 * '<S24>'  : 'flashHaileyECUv001/Federwegsensor HL'
 * '<S25>'  : 'flashHaileyECUv001/Federwegsensor HR'
 * '<S26>'  : 'flashHaileyECUv001/Federwegsensor VL'
 * '<S27>'  : 'flashHaileyECUv001/Federwegsensor VR'
 * '<S28>'  : 'flashHaileyECUv001/HV_uC_out'
 * '<S29>'  : 'flashHaileyECUv001/Lüfter Radiator Links 1'
 * '<S30>'  : 'flashHaileyECUv001/Lüfter Radiator Links 2'
 * '<S31>'  : 'flashHaileyECUv001/Lüfter Radiator Rechts 1'
 * '<S32>'  : 'flashHaileyECUv001/Lüfter Radiator Rechts 2'
 * '<S33>'  : 'flashHaileyECUv001/MainDlg1'
 * '<S34>'  : 'flashHaileyECUv001/N110_TPDO0'
 * '<S35>'  : 'flashHaileyECUv001/N111_TPDO0'
 * '<S36>'  : 'flashHaileyECUv001/Plusversorgung Dashboard'
 * '<S37>'  : 'flashHaileyECUv001/Plusversorgung Pedalerie'
 * '<S38>'  : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor'
 * '<S39>'  : 'flashHaileyECUv001/Power_Enable1'
 * '<S40>'  : 'flashHaileyECUv001/R2D LED'
 * '<S41>'  : 'flashHaileyECUv001/R2D Summer'
 * '<S42>'  : 'flashHaileyECUv001/R2D Taster'
 * '<S43>'  : 'flashHaileyECUv001/Raddrehzahlsensor VL'
 * '<S44>'  : 'flashHaileyECUv001/Raddrehzahlsensor VR'
 * '<S45>'  : 'flashHaileyECUv001/Reku Schalter Cockpit1'
 * '<S46>'  : 'flashHaileyECUv001/State_of_the_Cart'
 * '<S47>'  : 'flashHaileyECUv001/Subsystem'
 * '<S48>'  : 'flashHaileyECUv001/TS Activation Schalter Cockpit'
 * '<S49>'  : 'flashHaileyECUv001/TSAMK X08'
 * '<S50>'  : 'flashHaileyECUv001/TSAMK X140 Links'
 * '<S51>'  : 'flashHaileyECUv001/TSAMK X140 Rechts'
 * '<S52>'  : 'flashHaileyECUv001/TempMessage'
 * '<S53>'  : 'flashHaileyECUv001/Wasserkühlung Pumpe links nopwm'
 * '<S54>'  : 'flashHaileyECUv001/Wasserkühlung Pumpe rechts nopwm'
 * '<S55>'  : 'flashHaileyECUv001/capitane'
 * '<S56>'  : 'flashHaileyECUv001/mBMS_FuncSTAT'
 * '<S57>'  : 'flashHaileyECUv001/ADC_UBAT3/ADC_ChannelInit'
 * '<S58>'  : 'flashHaileyECUv001/ADC_UBAT3/ADC_Get'
 * '<S59>'  : 'flashHaileyECUv001/ADC_UBAT5/ADC_ChannelInit'
 * '<S60>'  : 'flashHaileyECUv001/ADC_UBAT5/ADC_Get'
 * '<S61>'  : 'flashHaileyECUv001/ADC_UBAT6/ADC_ChannelInit'
 * '<S62>'  : 'flashHaileyECUv001/ADC_UBAT6/ADC_Get'
 * '<S63>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/IO_CAN_ConfigMsg'
 * '<S64>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/IO_CAN_ReadMsg'
 * '<S65>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking1'
 * '<S66>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking10'
 * '<S67>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking11'
 * '<S68>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking2'
 * '<S69>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking3'
 * '<S70>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking4'
 * '<S71>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking5'
 * '<S72>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking6'
 * '<S73>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking7'
 * '<S74>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking8'
 * '<S75>'  : 'flashHaileyECUv001/AMK_Actual_Values1_1/bit_unpacking9'
 * '<S76>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/IO_CAN_ConfigMsg'
 * '<S77>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/IO_CAN_ReadMsg'
 * '<S78>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking1'
 * '<S79>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking10'
 * '<S80>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking11'
 * '<S81>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking2'
 * '<S82>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking3'
 * '<S83>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking4'
 * '<S84>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking5'
 * '<S85>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking6'
 * '<S86>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking7'
 * '<S87>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking8'
 * '<S88>'  : 'flashHaileyECUv001/AMK_Actual_Values1_2/bit_unpacking9'
 * '<S89>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/IO_CAN_ConfigMsg'
 * '<S90>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/IO_CAN_ReadMsg'
 * '<S91>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/bit_unpacking1'
 * '<S92>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/bit_unpacking2'
 * '<S93>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/bit_unpacking3'
 * '<S94>'  : 'flashHaileyECUv001/AMK_Actual_Values2_3/bit_unpacking4'
 * '<S95>'  : 'flashHaileyECUv001/AMK_Actual_Values2_4/IO_CAN_ConfigMsg'
 * '<S96>'  : 'flashHaileyECUv001/AMK_Actual_Values2_4/IO_CAN_ReadMsg'
 * '<S97>'  : 'flashHaileyECUv001/AMK_Actual_Values2_4/bit_unpacking1'
 * '<S98>'  : 'flashHaileyECUv001/AMK_Actual_Values2_4/bit_unpacking2'
 * '<S99>'  : 'flashHaileyECUv001/AMK_Actual_Values2_4/bit_unpacking3'
 * '<S100>' : 'flashHaileyECUv001/AMK_Actual_Values2_4/bit_unpacking4'
 * '<S101>' : 'flashHaileyECUv001/AMK_Setpoints_1/IO_CAN_ConfigMsg'
 * '<S102>' : 'flashHaileyECUv001/AMK_Setpoints_1/IO_CAN_WriteMsg'
 * '<S103>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing1'
 * '<S104>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing2'
 * '<S105>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing3'
 * '<S106>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing4'
 * '<S107>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing5'
 * '<S108>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing6'
 * '<S109>' : 'flashHaileyECUv001/AMK_Setpoints_1/bit_packing7'
 * '<S110>' : 'flashHaileyECUv001/AMK_Setpoints_2/IO_CAN_ConfigMsg'
 * '<S111>' : 'flashHaileyECUv001/AMK_Setpoints_2/IO_CAN_WriteMsg'
 * '<S112>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing1'
 * '<S113>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing2'
 * '<S114>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing3'
 * '<S115>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing4'
 * '<S116>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing5'
 * '<S117>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing6'
 * '<S118>' : 'flashHaileyECUv001/AMK_Setpoints_2/bit_packing7'
 * '<S119>' : 'flashHaileyECUv001/AMK_Setpoints_3/IO_CAN_ConfigMsg'
 * '<S120>' : 'flashHaileyECUv001/AMK_Setpoints_3/IO_CAN_ReadMsg'
 * '<S121>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking1'
 * '<S122>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking2'
 * '<S123>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking3'
 * '<S124>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking4'
 * '<S125>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking5'
 * '<S126>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking6'
 * '<S127>' : 'flashHaileyECUv001/AMK_Setpoints_3/bit_unpacking7'
 * '<S128>' : 'flashHaileyECUv001/AMK_Setpoints_4/IO_CAN_ConfigMsg'
 * '<S129>' : 'flashHaileyECUv001/AMK_Setpoints_4/IO_CAN_ReadMsg'
 * '<S130>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking1'
 * '<S131>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking2'
 * '<S132>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking3'
 * '<S133>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking4'
 * '<S134>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking5'
 * '<S135>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking6'
 * '<S136>' : 'flashHaileyECUv001/AMK_Setpoints_4/bit_unpacking7'
 * '<S137>' : 'flashHaileyECUv001/AkkuControl/IO_CAN_ConfigMsg'
 * '<S138>' : 'flashHaileyECUv001/AkkuControl/IO_CAN_WriteMsg'
 * '<S139>' : 'flashHaileyECUv001/AkkuControl/bit_packing1'
 * '<S140>' : 'flashHaileyECUv001/Bremsdrucksensor/ADC_ChannelInit'
 * '<S141>' : 'flashHaileyECUv001/Bremsdrucksensor/ADC_Get'
 * '<S142>' : 'flashHaileyECUv001/Bremsdrucksensor/POWER_Set_Init'
 * '<S143>' : 'flashHaileyECUv001/Bremslicht/IO_DO_GetCur'
 * '<S144>' : 'flashHaileyECUv001/Bremslicht/IO_DO_GetVoltage'
 * '<S145>' : 'flashHaileyECUv001/Bremslicht/IO_DO_Init'
 * '<S146>' : 'flashHaileyECUv001/Bremslicht/IO_DO_ResetProtection'
 * '<S147>' : 'flashHaileyECUv001/Bremslicht/IO_DO_Set'
 * '<S148>' : 'flashHaileyECUv001/Bremslicht/compare2FET_PROT_REENABLE'
 * '<S149>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO0'
 * '<S150>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO1'
 * '<S151>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO2'
 * '<S152>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3'
 * '<S153>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO1'
 * '<S154>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO2'
 * '<S155>' : 'flashHaileyECUv001/DV-Lenkung/NMTZeroMsg1'
 * '<S156>' : 'flashHaileyECUv001/DV-Lenkung/SYNC'
 * '<S157>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO0/IO_CAN_ConfigMsg'
 * '<S158>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO0/IO_CAN_ReadMsg'
 * '<S159>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO0/bit_unpacking1'
 * '<S160>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO1/IO_CAN_ConfigMsg'
 * '<S161>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO1/IO_CAN_ReadMsg'
 * '<S162>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO1/bit_unpacking1'
 * '<S163>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO1/bit_unpacking2'
 * '<S164>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO2/IO_CAN_ConfigMsg'
 * '<S165>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO2/IO_CAN_ReadMsg'
 * '<S166>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO2/bit_unpacking1'
 * '<S167>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO2/bit_unpacking2'
 * '<S168>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3/IO_CAN_ConfigMsg'
 * '<S169>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3/IO_CAN_ReadMsg'
 * '<S170>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3/bit_unpacking1'
 * '<S171>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3/bit_unpacking2'
 * '<S172>' : 'flashHaileyECUv001/DV-Lenkung/N18_TPDO3/bit_unpacking3'
 * '<S173>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO1/IO_CAN_ConfigMsg'
 * '<S174>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO1/IO_CAN_WriteMsg'
 * '<S175>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO1/bit_packing1'
 * '<S176>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO1/bit_packing2'
 * '<S177>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO2/IO_CAN_ConfigMsg'
 * '<S178>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO2/IO_CAN_WriteMsg'
 * '<S179>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO2/bit_packing1'
 * '<S180>' : 'flashHaileyECUv001/DV-Lenkung/N1_TPDO2/bit_packing2'
 * '<S181>' : 'flashHaileyECUv001/DV-Lenkung/NMTZeroMsg1/IO_CAN_ConfigMsg'
 * '<S182>' : 'flashHaileyECUv001/DV-Lenkung/NMTZeroMsg1/IO_CAN_WriteMsg'
 * '<S183>' : 'flashHaileyECUv001/DV-Lenkung/NMTZeroMsg1/bit_packing1'
 * '<S184>' : 'flashHaileyECUv001/DV-Lenkung/NMTZeroMsg1/bit_packing2'
 * '<S185>' : 'flashHaileyECUv001/DV-Lenkung/SYNC/IO_CAN_ConfigMsg'
 * '<S186>' : 'flashHaileyECUv001/DV-Lenkung/SYNC/IO_CAN_WriteMsg'
 * '<S187>' : 'flashHaileyECUv001/Debugmess1/IO_CAN_ConfigMsg'
 * '<S188>' : 'flashHaileyECUv001/Debugmess1/IO_CAN_WriteMsg'
 * '<S189>' : 'flashHaileyECUv001/Debugmess1/bit_packing1'
 * '<S190>' : 'flashHaileyECUv001/Debugmess1/bit_packing2'
 * '<S191>' : 'flashHaileyECUv001/Debugmess1/bit_packing3'
 * '<S192>' : 'flashHaileyECUv001/Debugmess1/bit_packing4'
 * '<S193>' : 'flashHaileyECUv001/Debugmess1/bit_packing5'
 * '<S194>' : 'flashHaileyECUv001/Debugmess1/bit_packing6'
 * '<S195>' : 'flashHaileyECUv001/Debugmess1/bit_packing7'
 * '<S196>' : 'flashHaileyECUv001/Debugmess2/IO_CAN_ConfigMsg'
 * '<S197>' : 'flashHaileyECUv001/Debugmess2/IO_CAN_WriteMsg'
 * '<S198>' : 'flashHaileyECUv001/Debugmess2/bit_packing1'
 * '<S199>' : 'flashHaileyECUv001/Debugmess2/bit_packing2'
 * '<S200>' : 'flashHaileyECUv001/Debugmess2/bit_packing3'
 * '<S201>' : 'flashHaileyECUv001/Debugmess2/bit_packing4'
 * '<S202>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM1'
 * '<S203>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM2'
 * '<S204>' : 'flashHaileyECUv001/EBS Control Unit/Durcksensor BP1'
 * '<S205>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM1/IO_DO_Init'
 * '<S206>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM1/IO_DO_ResetProtection'
 * '<S207>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM1/IO_DO_Set'
 * '<S208>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM1/compare2FET_PROT_REENABLE'
 * '<S209>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM2/IO_DO_Init'
 * '<S210>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM2/IO_DO_ResetProtection'
 * '<S211>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM2/IO_DO_Set'
 * '<S212>' : 'flashHaileyECUv001/EBS Control Unit/DV-Ventil QM2/compare2FET_PROT_REENABLE'
 * '<S213>' : 'flashHaileyECUv001/EBS Control Unit/Durcksensor BP1/ADC_ChannelInit'
 * '<S214>' : 'flashHaileyECUv001/EBS Control Unit/Durcksensor BP1/ADC_Get'
 * '<S215>' : 'flashHaileyECUv001/Federwegsensor HL/ADC_ChannelInit'
 * '<S216>' : 'flashHaileyECUv001/Federwegsensor HL/ADC_Get'
 * '<S217>' : 'flashHaileyECUv001/Federwegsensor HR/ADC_ChannelInit'
 * '<S218>' : 'flashHaileyECUv001/Federwegsensor HR/ADC_Get'
 * '<S219>' : 'flashHaileyECUv001/Federwegsensor VL/ADC_ChannelInit'
 * '<S220>' : 'flashHaileyECUv001/Federwegsensor VL/ADC_Get'
 * '<S221>' : 'flashHaileyECUv001/Federwegsensor VR/ADC_ChannelInit'
 * '<S222>' : 'flashHaileyECUv001/Federwegsensor VR/ADC_Get'
 * '<S223>' : 'flashHaileyECUv001/HV_uC_out/IO_CAN_ConfigMsg'
 * '<S224>' : 'flashHaileyECUv001/HV_uC_out/IO_CAN_ReadMsg'
 * '<S225>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking1'
 * '<S226>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking2'
 * '<S227>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking3'
 * '<S228>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking4'
 * '<S229>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking5'
 * '<S230>' : 'flashHaileyECUv001/HV_uC_out/bit_unpacking6'
 * '<S231>' : 'flashHaileyECUv001/Lüfter Radiator Links 1/IO_PWM_GetCur'
 * '<S232>' : 'flashHaileyECUv001/Lüfter Radiator Links 1/IO_PWM_Init'
 * '<S233>' : 'flashHaileyECUv001/Lüfter Radiator Links 1/IO_PWM_ResetProtection'
 * '<S234>' : 'flashHaileyECUv001/Lüfter Radiator Links 1/IO_PWM_SetDuty'
 * '<S235>' : 'flashHaileyECUv001/Lüfter Radiator Links 1/compare2FET_PROT_REENABLE'
 * '<S236>' : 'flashHaileyECUv001/Lüfter Radiator Links 2/IO_PWM_GetCur'
 * '<S237>' : 'flashHaileyECUv001/Lüfter Radiator Links 2/IO_PWM_Init'
 * '<S238>' : 'flashHaileyECUv001/Lüfter Radiator Links 2/IO_PWM_ResetProtection'
 * '<S239>' : 'flashHaileyECUv001/Lüfter Radiator Links 2/IO_PWM_SetDuty'
 * '<S240>' : 'flashHaileyECUv001/Lüfter Radiator Links 2/compare2FET_PROT_REENABLE'
 * '<S241>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 1/IO_PWM_GetCur'
 * '<S242>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 1/IO_PWM_Init'
 * '<S243>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 1/IO_PWM_ResetProtection'
 * '<S244>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 1/IO_PWM_SetDuty'
 * '<S245>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 1/compare2FET_PROT_REENABLE'
 * '<S246>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 2/IO_PWM_GetCur'
 * '<S247>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 2/IO_PWM_Init'
 * '<S248>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 2/IO_PWM_ResetProtection'
 * '<S249>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 2/IO_PWM_SetDuty'
 * '<S250>' : 'flashHaileyECUv001/Lüfter Radiator Rechts 2/compare2FET_PROT_REENABLE'
 * '<S251>' : 'flashHaileyECUv001/MainDlg1/MainDlg_basic'
 * '<S252>' : 'flashHaileyECUv001/N110_TPDO0/IO_CAN_ConfigMsg'
 * '<S253>' : 'flashHaileyECUv001/N110_TPDO0/IO_CAN_ReadMsg'
 * '<S254>' : 'flashHaileyECUv001/N110_TPDO0/bit_unpacking1'
 * '<S255>' : 'flashHaileyECUv001/N110_TPDO0/bit_unpacking2'
 * '<S256>' : 'flashHaileyECUv001/N111_TPDO0/IO_CAN_ConfigMsg'
 * '<S257>' : 'flashHaileyECUv001/N111_TPDO0/IO_CAN_ReadMsg'
 * '<S258>' : 'flashHaileyECUv001/N111_TPDO0/bit_unpacking1'
 * '<S259>' : 'flashHaileyECUv001/N111_TPDO0/bit_unpacking2'
 * '<S260>' : 'flashHaileyECUv001/Plusversorgung Dashboard/IO_DO_GetCur'
 * '<S261>' : 'flashHaileyECUv001/Plusversorgung Dashboard/IO_DO_GetVoltage'
 * '<S262>' : 'flashHaileyECUv001/Plusversorgung Dashboard/IO_DO_Init'
 * '<S263>' : 'flashHaileyECUv001/Plusversorgung Dashboard/IO_DO_ResetProtection'
 * '<S264>' : 'flashHaileyECUv001/Plusversorgung Dashboard/IO_DO_Set'
 * '<S265>' : 'flashHaileyECUv001/Plusversorgung Dashboard/compare2FET_PROT_REENABLE'
 * '<S266>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/IO_DO_GetCur'
 * '<S267>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/IO_DO_GetVoltage'
 * '<S268>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/IO_DO_Init'
 * '<S269>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/IO_DO_ResetProtection'
 * '<S270>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/IO_DO_Set'
 * '<S271>' : 'flashHaileyECUv001/Plusversorgung Pedalerie/compare2FET_PROT_REENABLE'
 * '<S272>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/IO_DO_GetCur'
 * '<S273>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/IO_DO_GetVoltage'
 * '<S274>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/IO_DO_Init'
 * '<S275>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/IO_DO_ResetProtection'
 * '<S276>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/IO_DO_Set'
 * '<S277>' : 'flashHaileyECUv001/Plusversorung Lenkwinkelsensor/compare2FET_PROT_REENABLE'
 * '<S278>' : 'flashHaileyECUv001/Power_Enable1/IO_POWER_Set_POWERSTAGE'
 * '<S279>' : 'flashHaileyECUv001/Power_Enable1/IO_POWER_Set_SSW0'
 * '<S280>' : 'flashHaileyECUv001/Power_Enable1/IO_POWER_Set_SSW1'
 * '<S281>' : 'flashHaileyECUv001/Power_Enable1/IO_POWER_Set_SSW2'
 * '<S282>' : 'flashHaileyECUv001/R2D LED/IO_DO_GetCur'
 * '<S283>' : 'flashHaileyECUv001/R2D LED/IO_DO_GetVoltage'
 * '<S284>' : 'flashHaileyECUv001/R2D LED/IO_DO_Init'
 * '<S285>' : 'flashHaileyECUv001/R2D LED/IO_DO_ResetProtection'
 * '<S286>' : 'flashHaileyECUv001/R2D LED/IO_DO_Set'
 * '<S287>' : 'flashHaileyECUv001/R2D LED/compare2FET_PROT_REENABLE'
 * '<S288>' : 'flashHaileyECUv001/R2D Summer/IO_DO_GetCur'
 * '<S289>' : 'flashHaileyECUv001/R2D Summer/IO_DO_GetVoltage'
 * '<S290>' : 'flashHaileyECUv001/R2D Summer/IO_DO_Init'
 * '<S291>' : 'flashHaileyECUv001/R2D Summer/IO_DO_ResetProtection'
 * '<S292>' : 'flashHaileyECUv001/R2D Summer/IO_DO_Set'
 * '<S293>' : 'flashHaileyECUv001/R2D Summer/compare2FET_PROT_REENABLE'
 * '<S294>' : 'flashHaileyECUv001/R2D Taster/ADC_ChannelInit'
 * '<S295>' : 'flashHaileyECUv001/R2D Taster/ADC_Get'
 * '<S296>' : 'flashHaileyECUv001/Raddrehzahlsensor VL/IO_PWD_ComplexGet'
 * '<S297>' : 'flashHaileyECUv001/Raddrehzahlsensor VL/PWD_ComplexInit'
 * '<S298>' : 'flashHaileyECUv001/Raddrehzahlsensor VR/IO_PWD_ComplexGet'
 * '<S299>' : 'flashHaileyECUv001/Raddrehzahlsensor VR/PWD_ComplexInit'
 * '<S300>' : 'flashHaileyECUv001/Reku Schalter Cockpit1/ADC_ChannelInit'
 * '<S301>' : 'flashHaileyECUv001/Reku Schalter Cockpit1/ADC_Get'
 * '<S302>' : 'flashHaileyECUv001/Subsystem/action chart'
 * '<S303>' : 'flashHaileyECUv001/TS Activation Schalter Cockpit/ADC_ChannelInit'
 * '<S304>' : 'flashHaileyECUv001/TS Activation Schalter Cockpit/ADC_Get'
 * '<S305>' : 'flashHaileyECUv001/TSAMK X08/IO_DO_GetCur'
 * '<S306>' : 'flashHaileyECUv001/TSAMK X08/IO_DO_GetVoltage'
 * '<S307>' : 'flashHaileyECUv001/TSAMK X08/IO_DO_Init'
 * '<S308>' : 'flashHaileyECUv001/TSAMK X08/IO_DO_ResetProtection'
 * '<S309>' : 'flashHaileyECUv001/TSAMK X08/IO_DO_Set'
 * '<S310>' : 'flashHaileyECUv001/TSAMK X08/compare2FET_PROT_REENABLE'
 * '<S311>' : 'flashHaileyECUv001/TSAMK X140 Links/IO_DO_GetCur'
 * '<S312>' : 'flashHaileyECUv001/TSAMK X140 Links/IO_DO_GetVoltage'
 * '<S313>' : 'flashHaileyECUv001/TSAMK X140 Links/IO_DO_Init'
 * '<S314>' : 'flashHaileyECUv001/TSAMK X140 Links/IO_DO_ResetProtection'
 * '<S315>' : 'flashHaileyECUv001/TSAMK X140 Links/IO_DO_Set'
 * '<S316>' : 'flashHaileyECUv001/TSAMK X140 Links/compare2FET_PROT_REENABLE'
 * '<S317>' : 'flashHaileyECUv001/TSAMK X140 Rechts/IO_DO_GetCur'
 * '<S318>' : 'flashHaileyECUv001/TSAMK X140 Rechts/IO_DO_GetVoltage'
 * '<S319>' : 'flashHaileyECUv001/TSAMK X140 Rechts/IO_DO_Init'
 * '<S320>' : 'flashHaileyECUv001/TSAMK X140 Rechts/IO_DO_ResetProtection'
 * '<S321>' : 'flashHaileyECUv001/TSAMK X140 Rechts/IO_DO_Set'
 * '<S322>' : 'flashHaileyECUv001/TSAMK X140 Rechts/compare2FET_PROT_REENABLE'
 * '<S323>' : 'flashHaileyECUv001/TempMessage/IO_CAN_ConfigMsg'
 * '<S324>' : 'flashHaileyECUv001/TempMessage/IO_CAN_WriteMsg'
 * '<S325>' : 'flashHaileyECUv001/TempMessage/bit_packing1'
 * '<S326>' : 'flashHaileyECUv001/TempMessage/bit_packing2'
 * '<S327>' : 'flashHaileyECUv001/TempMessage/bit_packing3'
 * '<S328>' : 'flashHaileyECUv001/TempMessage/bit_packing4'
 * '<S329>' : 'flashHaileyECUv001/Wasserkühlung Pumpe links nopwm/IO_DO_Init'
 * '<S330>' : 'flashHaileyECUv001/Wasserkühlung Pumpe links nopwm/IO_DO_ResetProtection'
 * '<S331>' : 'flashHaileyECUv001/Wasserkühlung Pumpe links nopwm/IO_DO_Set'
 * '<S332>' : 'flashHaileyECUv001/Wasserkühlung Pumpe links nopwm/compare2FET_PROT_REENABLE'
 * '<S333>' : 'flashHaileyECUv001/Wasserkühlung Pumpe rechts nopwm/IO_DO_Init'
 * '<S334>' : 'flashHaileyECUv001/Wasserkühlung Pumpe rechts nopwm/IO_DO_ResetProtection'
 * '<S335>' : 'flashHaileyECUv001/Wasserkühlung Pumpe rechts nopwm/IO_DO_Set'
 * '<S336>' : 'flashHaileyECUv001/Wasserkühlung Pumpe rechts nopwm/compare2FET_PROT_REENABLE'
 * '<S337>' : 'flashHaileyECUv001/mBMS_FuncSTAT/IO_CAN_ConfigMsg'
 * '<S338>' : 'flashHaileyECUv001/mBMS_FuncSTAT/IO_CAN_ReadMsg'
 * '<S339>' : 'flashHaileyECUv001/mBMS_FuncSTAT/Trigger_Block'
 * '<S340>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking1'
 * '<S341>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking10'
 * '<S342>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking11'
 * '<S343>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking12'
 * '<S344>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking13'
 * '<S345>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking14'
 * '<S346>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking15'
 * '<S347>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking16'
 * '<S348>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking17'
 * '<S349>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking18'
 * '<S350>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking19'
 * '<S351>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking2'
 * '<S352>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking20'
 * '<S353>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking21'
 * '<S354>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking22'
 * '<S355>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking23'
 * '<S356>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking24'
 * '<S357>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking25'
 * '<S358>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking26'
 * '<S359>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking27'
 * '<S360>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking28'
 * '<S361>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking29'
 * '<S362>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking3'
 * '<S363>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking30'
 * '<S364>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking31'
 * '<S365>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking32'
 * '<S366>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking33'
 * '<S367>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking34'
 * '<S368>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking35'
 * '<S369>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking36'
 * '<S370>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking37'
 * '<S371>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking38'
 * '<S372>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking39'
 * '<S373>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking4'
 * '<S374>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking40'
 * '<S375>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking41'
 * '<S376>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking42'
 * '<S377>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking43'
 * '<S378>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking44'
 * '<S379>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking5'
 * '<S380>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking6'
 * '<S381>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking7'
 * '<S382>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking8'
 * '<S383>' : 'flashHaileyECUv001/mBMS_FuncSTAT/bit_unpacking9'
 * '<S384>' : 'flashHaileyECUv001/mBMS_FuncSTAT/IO_CAN_ReadMsg/IO_CAN_ReadMsg'
 * '<S385>' : 'flashHaileyECUv001/mBMS_FuncSTAT/Trigger_Block/Compare To Constant'
 * '<S386>' : 'flashHaileyECUv001/mBMS_FuncSTAT/Trigger_Block/Counter Limited'
 * '<S387>' : 'flashHaileyECUv001/mBMS_FuncSTAT/Trigger_Block/Counter Limited/Increment Real World'
 * '<S388>' : 'flashHaileyECUv001/mBMS_FuncSTAT/Trigger_Block/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_flashHaileyECUv001_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
