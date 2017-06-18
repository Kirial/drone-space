

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Jun 18 00:19:05 2017
 */
/* Compiler settings for src_fraNiklas\Klient\RPC_drone_interface.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __RPC_drone_interface_h_h__
#define __RPC_drone_interface_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __cv_drone_int_INTERFACE_DEFINED__
#define __cv_drone_int_INTERFACE_DEFINED__

/* interface cv_drone_int */
/* [implicit_handle][version][uuid] */ 

int _askHoops( void);

int _askHoopX( 
    int n);

int _askHoopY( 
    int n);

int _askHoopH( 
    int n);

int _askHoopW( 
    int n);

int _askQR( void);

int _askQRX( 
    int n);

int _askQRY( 
    int n);

int _askQRsize( 
    int n);

int _askYaw( void);

int _askHeight( void);

int _askPitch( void);

int _askRoll( void);

int _inctruct( 
    int x,
    int y,
    int z,
    int alfa);

int _takeOff( void);

int _land( void);


extern handle_t hcv_drone_intBinding;


extern RPC_IF_HANDLE cv_drone_int_v1_0_c_ifspec;
extern RPC_IF_HANDLE cv_drone_int_v1_0_s_ifspec;
#endif /* __cv_drone_int_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


