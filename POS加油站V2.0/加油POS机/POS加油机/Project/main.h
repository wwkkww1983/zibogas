/******************************************************************************
Copyright 2005 大连易达通电子有限公司
All rights riserved.

文件名  ：main.h
模块名称：定义了所有的数据类型

当前版本：0.0.1
修改人	：许岩
完成日期：2005.04.06
升级说明：create
******************************************************************************/
#ifndef __MAIN_H__
#define __MAIN_H__


//全局条件编译控制
//#define EN_WDT
//#define TEST_CARD

#include "data_type.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <termio.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h> 
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>



#include "macrodef.h"
#include "common_exp.h"
#include "CommonFunc.h"
#include "printer.h"
#include "IODrive.h"
#include "Ffile.h"
#include "cfile.h"
#include "bfile.h"
#include "tms.h"
#include "libCommu.h"
#include "Wireless_Drv.h"
#include "Protocol_Drv.h"
#include "mifs.h"
#include "mifscommon.h"
#include "Iccard.h"



#include "ydt.h"
#include "utils.h"
#include "opercard.h"
#include "tcpip.h"
#include "sam_card.h"
#include "m1card.h"
#include "SIM200.h"
#include "menu.h"
#include "db.h"
#include "Function.h"

#define 	ok			        	(0)
#define     notok                   (0xFF)
#define 	LOW						(0)
#define 	HIGH		       		(1)
#define 	ON			        	(0)
#define 	OFF		        		(1)

#define ORG_NORMAL		0
#define ORG_ASCII		1
#define ORG_BCD			2
#define ORG_HEX			3


#define DebugPrint	printf
#define resetpos() (*(void(*)())0)()

#define OS_ENTER_CRITICAL()	
#define OS_EXIT_CRITICAL()

/*****************************************************************
 函数原型：System_Init()
 功能描述：参数等初始化
 参数描述：

 返回值：   无

 作  者：   许岩/刘及华
 日  期：   2012-11-24
 修改历史：
		日期        修改人      修改描述
		------      ---------   -------------
*****************************************************************/
INT8U System_Init(void);
void kuaijiefangshi(void);
/*****************************************************************
 函数原型：Debug_string(char *str)
 功能描述：串口调试输出函数
 参数描述：str打印的字符串

 返回值：   无

 作  者：   刘及华
 日  期：   2013-06-24
 修改历史：
		日期        修改人      修改描述
		------      ---------   -------------
*****************************************************************/
void Debug_string(char *str);
/*****************************************************************
 函数原型：zbClerkFileInit(void)
 功能描述：操作员文件初始化
 参数描述：	
				 
 返回值：	OK ? NOTOK
 
 作  者： 刘及华
 日  期：	2012-11-24
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
char zbClerkFileInit(void);
/*****************************************************************
 函数原型：appfile_Init(void)
 功能描述：用户文件系统初始化
 参数描述：	
				 
 返回值：	无
 
 作  者： 刘及华
 日  期：	2012-11-24
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
void appfile_Init(void);

void Debugprintf(const char *fmt, ...);
/*****************************************************************
 函数原型：zbClerkSaveFile(void)
 功能描述：操作员文件初始化
 参数描述：	
				 
 返回值：	OK ? NOTOK
 
 作  者： 刘及华
 日  期：	2012-11-24
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
char zbClerkSaveFile(void);
/*****************************************************************
 函数原型：zbClerkReadFile(void)
 功能描述：操作员文件初始化
 参数描述：	
				 
 返回值：	OK ? NOTOK
 
 作  者： 刘及华
 日  期：	2012-11-24
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
char zbClerkReadFile(void);
/*****************************************************************
 函数原型：Device_Handle_Init()
 功能描述：设备所有句柄初始化
 参数描述：	
				 
 返回值：	无
 
 作  者： 刘及华
 日  期：	2012-11-24
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
INT8U Device_Handle_Init(void);
/*****************************************************************
函数原型：LowBatteryDisplay
功能描述：本函数为电池电量显示
参数描述：无
参数名称：	输入/输出？	类型		描述
 作  者：   刘及华
 日  期：   2012-11-24
 修改历史：
		日期        修改人      修改描述
返 回 值：无
*****************************************************************/
INT8U LowBatteryDisplay(void);
/*****************************************************************
 函数原型：system_check()
 功能描述：系统自检以及gprs模块参数配置
 参数描述：	
				 
 返回值：	无
 
 作  者：	许岩
 日  期：	2004-09-17
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
*****************************************************************/
void system_check(void);

/******************************************************************************
 函数名称：TimeFormatChk
 功能描述：读时钟，看时钟格式是否正确
 参数描述：
 参数名称：	输入/输出？	类型		描述
				
 返  回  值：ok(0)-自检成功
				 notok(0xFF)-自检失败
				   
 作      者	：许岩
 日      期：2004-09-02
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
INT8U TimeFormatChk (void);

/******************************************************************************
 函数名称：TimeModify
 功能描述：要求输入时间，进行修改
 参数描述：
 参数名称：	输入/输出？	类型		描述
				
 返  回  值：无
				   
 作      者	：许岩
 日      期：2004-09-02
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void TimeModify(void);

/*****************************************************************
函数原型：SystemCheck
功能描述：本函数为系统检测
参数描述：无
参数名称：	输入/输出？	类型		描述
-----------		-----------	------	   	------- 
作    者： 刘及华 
日	  期： 2012-11-28
返 回 值：有
			 1:成功
			 0:失败
*****************************************************************/
INT8U SystemCheck(void);

/******************************************************************************
 函数名称：msystem
 功能描述：菜单->系统设置
 参数描述：
 参数名称：	输入/输出？	类型		描述
				
 返  回  值：无
				   
 作      者	：许岩
 日      期：2012-10-30
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void msystem(void);

/*****************************************************************
函数原型：unpackInt(unsigned char *msg)
功能描述：///\x00\x00\x00\x64 -> 100
参数描述：
参数名称：	输入/输出？	类型		描述
-----------		-----------	------	   	-------
返 回 值：无
*****************************************************************/

/******************************************************************************
 函数名称：query_capacity
 功能描述：查询记录空间
 参数描述：
 参数名称：	输入/输出？	类型		描述
				
 返  回  值：无
				   
 作      者	：许岩
 日      期：2012-10-30
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void query_capacity(void);

/******************************************************************************
 函数名称：Power_Down
 功能描述：休眠手持机
 参数名称：	输入/输出？	类型		描述
 输入		
 
 返  回  值：
 
 作      者	：于福勇/刘及华
 日      期：2012-11-27

 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void Power_Down (void);

/******************************************************************************
 函数名称：format_process
 功能描述：格式化处理
 参数描述：
 参数名称：	输入/输出？	类型		描述
				
 返  回  值：无
				   
 作      者	：许岩
 日      期：2012-10-30
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void format_process(void);
/*****************************************************************
函数原型：DisplayWelcomeMenu
功能描述：本函数为显示欢迎界面
参数描述：无
参数名称：	输入/输出？	类型		描述
-----------		-----------	------	   	-------
返 回 值：无
*****************************************************************/
void DisplayWelcomeMenu(void);
/*****************************************************************
 函数原型：Menu_Sure_or_Cancel
 功能描述：选择确认或者是取消界面，只有两个选项，
 参数描述：

 返回值：  -1或者是0

 作  者：   刘及华
 日  期：   2012-11-24
 修改历史：
		日期        修改人      修改描述
		------      ---------   -------------
*****************************************************************/
INT8U Menu_Sure_or_Cancel(const char * menu_line );
/*****************************************************************
函数原型：AppTimerISR
功能描述：定时器函数
参数描述：设置网络心跳时间
参数名称：	输入/输出？	类型		描述
-----------		-----------	------	   	------- 
作	  者： 刘及华 
返 回 值：无
*****************************************************************/
void AppTimerISR(void);
/******************************************************************************
 函数名称：Power_Down
 功能描述：休眠手持机
 参数名称：	输入/输出？	类型		描述
 输入		
 
 返  回  值：
 
 作      者	：于福勇/刘及华
 日      期：2012-11-27

 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void System_reset(void);
// *****************************************************************
// 功能：		AnalyAndDisplayNote
// 说明:		查询日结表，并显示日结信息
// 入口参数：	
// 出口参数：	Null
// 作者：
// 返回值：							
// *****************************************************************
void AnalyAndDisplayNote(INT8U * strTradeInfo);
/******************************************************************************
 函数名称：print_work_note_history
 功能描述：打印日结算历史票据
 参数名称：输入/输出？	类型		描述
 输入		
 
 返  回  值：
 
 作      者	：于福勇
 日      期：2004-09-02
 修改历史：
		日期		修改人		修改描述
		------		---------	-------------
******************************************************************************/
void print_work_note_his (INT8U * rec);
// *****************************************************************
// 功能：		query_note_record
// 说明:		查询日结小票
// 入口参数：	
// 出口参数：	Null
// 作者：
// 返回值：	-1 关机				
// *****************************************************************
int query_note_and_record(void);

#endif
