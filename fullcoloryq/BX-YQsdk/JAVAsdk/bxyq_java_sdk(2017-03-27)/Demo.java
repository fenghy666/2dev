package com.onbonbx.sdkdemo;
import java.util.ArrayList;

import com.onbonbx.yqsdk.YQException;
import com.onbonbx.yqsdk.bean.YQBaseTime.DateFormat;
import com.onbonbx.yqsdk.bean.YQBaseTime.TimeFormat;
import com.onbonbx.yqsdk.bean.YQBaseTime.WeekFormat;
import com.onbonbx.yqsdk.bean.YQCardInfo;
import com.onbonbx.yqsdk.bean.YQClock;
import com.onbonbx.yqsdk.bean.YQCount;
import com.onbonbx.yqsdk.bean.YQLunar;
import com.onbonbx.yqsdk.bean.YQPicUnit;
import com.onbonbx.yqsdk.bean.YQPicture;
import com.onbonbx.yqsdk.bean.YQProList;
import com.onbonbx.yqsdk.bean.YQProgram;
import com.onbonbx.yqsdk.bean.YQSensor;
import com.onbonbx.yqsdk.bean.YQSensor.YQSensorParitionType;
import com.onbonbx.yqsdk.bean.YQSensor.YQSensorType;
import com.onbonbx.yqsdk.bean.YQSensor.YQSensorUnit;
import com.onbonbx.yqsdk.bean.YQText;
import com.onbonbx.yqsdk.bean.YQTextUnit;
import com.onbonbx.yqsdk.bean.YQTime;
import com.onbonbx.yqsdk.bean.YQVideo;
import com.onbonbx.yqsdk.bean.YQVideoUnit;
import com.onbonbx.yqsdk.bean.YQDisplayEffect;
import com.onbonbx.yqsdk.bean.YQDynamic;
import com.onbonbx.yqsdk.bean.YQDynamicPic;
import com.onbonbx.yqsdk.bean.YQDynamicText;
import com.onbonbx.yqsdk.manager.YQCmdListener;
import com.onbonbx.yqsdk.manager.YQScreenClient;
import com.onbonbx.yqsdk.manager.YQScreenClient.NetMode;



public class Demo {
	
	private static final int SEARCH_CARDS = 0;
	
	private static final int SET_SCREEN_SIZE = 1;
	
	private static final int SCREEN_ON = 2;
	
	private static final int SCREEN_OFF = 3;
	
	private static final int GET_TIME = 4;
	
	private static final int SET_TIME = 5;
	
	private static final int GET_BRIGHTNESS = 6;
	
	private static final int MANUAL_BRIGHTNESS = 7;
	
	private static final int TIMING_BRIGHTNESS = 8;
	
	private static final int AUTO_BRIGHTNESS = 9;
	
	private static final int TIMING_SWITCH = 10;
	
	private static final int CANCEL_TIMING_SWITCH = 11;
	
	private static final int SET_VOLUME = 12;
	
	private static final int GET_VOLUME = 13;
	
	private static final int SWITCH_STORAGE = 14;
	
	private static final int GET_SCREEN_STATUS = 15;
	
	private static final String ipAddr = "192.168.3.5";
	
	public static void main(String[] args){
		
		//开启线程发送命令和节目
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				//命令demo
				sendCmd(SET_TIME);
				
				//发送普通节目demo
				//普通节目掉电保存
				sendProgram();

				//发送动态区
				//动态区掉电不保存，适用于频繁更新的区域
				sendDynamic();
				
			}

		}).start();

		print("主线程正在运行" + Thread.currentThread().getId());
	}

	/**
	 * 发送常用命令，所有命令都会阻塞线程
	 */
	private static void sendCmd(int num) {
		//192.168.3.5是控制器的IP地址，5000为超时时间5000毫秒，会阻塞线程
		//多条命令可以组合使用
		//创建客户端模式控制器
		YQScreenClient screen = new YQScreenClient(ipAddr, 5 * 1000);
		
		switch (num) {
		
		case SEARCH_CARDS://搜索控制器
		
			//若不知道控制器的IP地址，可以使用搜索功能搜索控制器
			//如下为搜索控制器，搜索时间为3000ms,会阻塞线程
			YQScreenClient manager = new YQScreenClient("192.168.3.255", 3 * 1000);

			ArrayList<YQCardInfo> cardInfos = manager.searchCards();
			if (cardInfos == null) {
				print("搜索失败");
				return;
			}
			for(YQCardInfo cardInfo : cardInfos){
				print("控制器信息：");
				print("控制器的型号：" + cardInfo.getCardType());
				print("控制器的IP：" + cardInfo.getIpAddr());
				print("控制器的网关：" + cardInfo.getGateWay());
				print("控制器的子网掩码：" + cardInfo.getNetMask());
				print("控制器的mac地址：" + cardInfo.getMacAddr());
				// 0-单机直连，控制器做服务器,1-服务器模式，控制器做客户端,2-web模式，控制器作为客户端	   
				print("控制器的网络模式：" + cardInfo.getClientMode());
				// 0-dhcp  1-静态ip
				print("控制器的IP模式：" + cardInfo.getIpMode());
				
				print("控制器的屏幕宽度：" + cardInfo.getWidth());
				print("控制器的屏幕高度：" + cardInfo.getHeight());
				print("控制器的安装地址：" + cardInfo.getName());
				print("控制器的条形码：" + cardInfo.getBarcode());
			}
			
			//搜索后如果未重新实例化YQScreenClient的对象，则需要重新设置网络模式和IP，才能继续发送命令和节目
//			manager.resetNetMode(NetMode.TCP_MODE);
//			manager.setHostIp("192.168.3.5");
//			//校时,使用系统时间
//			if (manager.setTime()) {
//				print("校时成功");
//			}else {
//				print("校时失败");
//			}
			break;
			
		//设置屏参
		case SET_SCREEN_SIZE:
			//控制器使用前，需要先设置屏幕参数，即屏幕的大小。设置屏参会重启控制器，整个过程大约14秒钟
			//注：只需要安装时设置一次即可，不需要每次都设置，注意屏幕的范围
			if (screen.setScreenSize(384, 384)) {
				print("设置屏幕参数成功");
			}else {
				print("设置屏幕参数失败！");
			}
			break;
			
		case SCREEN_OFF:
			//软件关机，不是断电，是指关掉屏幕的显示内容
			if (screen.setSwitchOnOff(false)) {
				print("关机成功");
			}else {
				print("关机失败");
			}
			break;
			
		case SCREEN_ON:
			//软件开机
			if (screen.setSwitchOnOff(true)) {
				print("开机成功");
			}else {
				print("开机失败");
			}
			break;
			
		case SET_TIME:
			//校时,使用系统时间
			if (screen.setTime()) {
				print("校时成功");
			}else {
				print("校时失败");
			}
			
			//校时,自定义时间
//			if (screen.setTime(2016, 12, 25, 18, 30, 30)) {
//				print("校时成功");
//			}else {
//				print("校时失败");
//			}
			break;
			
		case GET_TIME:
			//获取控制器时间，格式 2011-8-30 9:50:38 Tue
			String getTime = null;
			if ((getTime = screen.getTime()) != null) {
				print("获取时间：" + getTime);
			}else {
				print("获取时间失败");
			}
			break;
			
		case GET_BRIGHTNESS:
			//获取控制器亮度，1-255
			int brightness = screen.getBrightness();
			print("控制器的亮度值：" + brightness);
			break;
			
		case MANUAL_BRIGHTNESS:
			//手动调节亮度,范围1-255
			if (screen.manualAdjBrightness(100)) {
				print("手动调节亮度成功");
			}else {
				print("手动调亮失败");
			}
			break;
			
		case TIMING_BRIGHTNESS:
			//定时调亮,要求有四组值
			String[] time = {"08:00", "12:00", "16:00", "20:00"};
			int[] value = {150, 200, 140, 90};
			if (screen.timeAdjBrightness(time, value)) {
				print("设置定时调亮成功");
			}else {
				print("设置定时调亮失败");
			}
			break;
			
		case AUTO_BRIGHTNESS:
			//自动调亮，需要外接多功能板和亮度传感器
			if (screen.autoAdjBrightness()) {
				print("自动调亮设置成功");
			}else {
				print("自动调亮设置失败");
			}
			
			break;
		
		case GET_VOLUME:
			//获取音量
			int volume = screen.getVolume();
			print("当前音量：" + volume);
			break;
			
		case SET_VOLUME:
			//设置音量，0-100
			if (screen.setVolume(60)) {
				print("设置音量成功");
			}else {
				print("设置音量失败");
			}
			break;
			
		case TIMING_SWITCH:
			//定时开关机,最多四组值，必须成对出现
			String[] onTime = {"08:00", "09:00", "12:00", "18:00"};
			String[] offTime = {"08:20", "09:15", "13:00", "23:00"};
			if (screen.setTimingSwitch(onTime, offTime)) {
				print("定时开关机成功");
			}else {
				print("定时开关机失败");
			}
			break;
			
		case CANCEL_TIMING_SWITCH:
			//取消定时开关机
			if (screen.cancelTimingSwitch()) {
				print("取消定时开关机成功");
			}else {
				print("取消定时开关机失败");
			}
			break;
			
		case SWITCH_STORAGE:
			//切换存储介质,若存储介质不存在会失败
			if (screen.switchStorage(3)) {
				print("切换成功");
			}else {
				print("切换失败");
			}
			break;
			
		case GET_SCREEN_STATUS:
			//获取控制器的多条状态
			//0-版本号  1-屏幕参数 2-当前存储介质 3-亮度 4-音量            
			ArrayList<String> result = screen.getScreenStatus();
			if (result != null) {
				print("版本号：" + result.get(0));
				print("屏幕参数：" + result.get(1));
				print("当前存储介质：" + result.get(2));
				print("亮度：" + result.get(3));
				print("音量：" + result.get(4));
			}else {
				print("获取信息失败");
			}
			break;
		default:
			break;
		}


	}

	/**
	 * 发送动态区到控制器
	 */
	public static void sendDynamic(){
		//动态区可以和节目同时使用,也可以独立使用
		//创建一个图片动态区，编号1
		YQDynamic dynamic = new YQDynamic(0, 0, 128, 30, 0);
		//编号1
		dynamic.setAreaID(1);
		
		//设置动态区和节目的关系
		//1 关联节目绑定播放   0 关联节目播放完后播放
		dynamic.setProgramRelation(1);
		
		// 0xffff—全局区域。
		//0—关联节目 0，该动态区域与异步节目 0 一起播放
		//1—关联节目 1，该动态区域与异步节目 1 一起播放
		//N—关联节目 N，该动态区域与异步节目一起播放。
		dynamic.setRelatedProgram(0xffff);
		
		//  0— 动态区数据循环显示。
		//	1— 动态区数据顺序显示，显示完最后一页后就不再显示
		//	2— 动态区数据显示完成后静止显示最后一页数据。
		//	3— 动态区数据循环显示，超过设定时间后数据仍未更新时删除动态区信息。
		//	4--动态区数据循环显示，超过设定时间后数据仍未更新时播放 LOGO 图片
		dynamic.setRunMode(0);
		
		//0 立即播放(绑定节目一起播放)  1 自动轮播
		dynamic.setRunTime(0);
		
		//添加一张图片到动态区1
		YQDynamicPic pic1 = new YQDynamicPic("C:/Users/Li/Desktop/测试图片/flowers.jpg");
		//设置特技
		pic1.setDisplayEffects(YQDisplayEffect.RANDOM);
		//设置特技速度1-16
		pic1.setDisplaySpeed(4);
		//设置停留时间秒，0-255
		pic1.setStayTime(5);
	
		dynamic.addPic(pic1);
		
		//添加一张图片到动态区1
		YQDynamicPic pic2 = new YQDynamicPic("C:/Users/Li/Desktop/测试图片/surf.jpg");
		//设置特技
		pic1.setDisplayEffects(YQDisplayEffect.RANDOM);
		//设置特技速度1-16
		pic1.setDisplaySpeed(4);
		//设置停留时间秒，0-255
		pic1.setStayTime(5);
		
		dynamic.addPic(pic2);
		
		//创建客户端屏幕
		YQScreenClient screen = new YQScreenClient(ipAddr);
		//更新动态区
		if (screen.updateDynamic(dynamic)) {
			print("发送动态区1成功");
		}else {
			print("发送动态区1失败");
		}
		
		//创建动态区2，用于显示文字
		YQDynamic dynamic2 = new YQDynamic(0, 30, 128, 30, 1);
		//编号2
		dynamic2.setAreaID(2);
		
		//设置动态区和节目的关系
		//1 关联节目绑定播放   0 关联节目播放完后播放
		dynamic2.setProgramRelation(1);
		
		// 0xffff—全局区域。
		//0—关联节目 0，该动态区域与异步节目 0 一起播放
		//1—关联节目 1，该动态区域与异步节目 1 一起播放
		//N—关联节目 N，该动态区域与异步节目一起播放。
		dynamic2.setRelatedProgram(0xffff);
		
		//  0— 动态区数据循环显示。
		//	1— 动态区数据顺序显示，显示完最后一页后就不再显示
		//	2— 动态区数据显示完成后静止显示最后一页数据。
		//	3— 动态区数据循环显示，超过设定时间后数据仍未更新时删除动态区信息。
		//	4--动态区数据循环显示，超过设定时间后数据仍未更新时播放 LOGO 图片
		dynamic2.setRunMode(0);
		
		//0 立即播放(绑定节目一起播放)  1 自动轮播
		dynamic2.setRunTime(0);
		
		//创建动态区文本
		YQDynamicText text = new YQDynamicText("动态区文本测试");
		//设置文本字体
		text.setFontName("宋体")
		//设置字体大小
		.setFontSize(16)
		//是否开启反锯齿
		.setAntialias(false)
		//设置是否加粗
		.setBold(false)
		//设置是否斜体
		.setItalic(false)
		//设置是否下划线
		.setUnderline(false)
		//设置文本颜色
		.setTextColor(0xff00)
		//设置文本背景色
		.setBgColor(0xff000000);
		
		dynamic2.addText(text);
		
		//发送动态区2
		if (screen.updateDynamic(dynamic2)) {
			print("发送动态区2成功");
		}else {
			print("发送动态区2失败");
		}
		
		//5s后更新编号1区域
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		//创建动态区3，用于更新动态区id为1的区域
		YQDynamic dynamic3 = new YQDynamic(0, 0, 128, 30, 0);
		//编号1
		dynamic3.setAreaID(1);
		
		//设置动态区和节目的关系
		//1 关联节目绑定播放   0 关联节目播放完后播放
		dynamic3.setProgramRelation(1);
		
		// 0xffff—全局区域。
		//0—关联节目 0，该动态区域与异步节目 0 一起播放
		//1—关联节目 1，该动态区域与异步节目 1 一起播放
		//N—关联节目 N，该动态区域与异步节目一起播放。
		dynamic3.setRelatedProgram(0xffff);
		
		//  0— 动态区数据循环显示。
		//	1— 动态区数据顺序显示，显示完最后一页后就不再显示
		//	2— 动态区数据显示完成后静止显示最后一页数据。
		//	3— 动态区数据循环显示，超过设定时间后数据仍未更新时删除动态区信息。
		//	4--动态区数据循环显示，超过设定时间后数据仍未更新时播放 LOGO 图片
		dynamic3.setRunMode(0);
		
		//0 立即播放(绑定节目一起播放)  1 自动轮播
		dynamic3.setRunTime(0);
		
		//添加一张图片到动态区3
		YQDynamicPic picUpdate = new YQDynamicPic("C:/Users/Li/Desktop/测试图片/city.jpg");
		//设置特技
		picUpdate.setDisplayEffects(YQDisplayEffect.RANDOM);
		//设置特技速度1-16
		picUpdate.setDisplaySpeed(4);
		//设置停留时间秒，0-255
		picUpdate.setStayTime(5);
	
		dynamic3.addPic(picUpdate);
		
		//更新动态区编号1
		if (screen.updateDynamic(dynamic3)) {
			print("更新动态区编号1成功");
		}else {
			print("更新动态区编号1失败");
		}
		
		/*
		//动态区可以保存到控制器的磁盘上
		if (manager.saveDynamic(1)) {
			print("保存动态区1成功");
		}else {
			print("保存动态区1失败");
		}
		
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}
		
		//删除磁盘上保存的动态区
		if (manager.cleanDynamic()) {
			print("清除动态区成功");
		}else {
			print("清除动态区失败");
		}
		*/
		
		//5s后删除动态区
		try {
			Thread.sleep(5 * 1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		//删除动态区，编号1
		if (screen.deleteDynamic(1)) {
			print("删除动态区编号1成功");
		}else {
			print("删除动态区编号1失败");
		}
		
		try {
			Thread.sleep(200);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		//删除动态区，编号2
		if (screen.deleteDynamic(2)) {
			print("删除动态区编号2成功");
		}else {
			print("删除动态区编号2失败");
		}
	}
	
	/**
	 * 发送节目
	 */
	public static void sendProgram(){
		/**
		 * 发送节目的流程
		 * 1. 创建节目列表
		 * 2. 创建节目，设置节目属性
		 * 3. 创建分区和分区数据
		 * 4. 添加分区到节目，添加节目到节目列表
		 * 5. 使用YQScreenClient发送节目
		 */
		//创建一个节目列表
		YQProList list = new YQProList();
		
		//创建一个节目1
		YQProgram program1 = createProgram();
		
		//创建一个视频分区，并添加到节目1中
		YQVideo video = createVideo();
		program1.add(video);
		
		//创建一个时间区，并添加到节目1中
		//后添加的分区会盖在前边添加的分区上
		YQTime time = createTime();
		program1.add(time);
		
		//创建一个图片区，并添加到节目1
		YQPicture picture = createPicture();
		program1.add(picture);
		
		//添加节目到节目列表
		list.add(program1);
		
		//新建节目2
		YQProgram program2 = createProgram();
		
		//新建一个文本分区，并添加到节目2中
		YQText text = createText();
		program2.add(text);
		
		list.add(program2);
		
		//新建节目3
		YQProgram program3 = createProgram();
		
		//新建一个表盘区
		YQClock clock = createClock();
		program3.add(clock);
		
		//新建一个传感器分区（温度）,添加到节目3
		YQSensor temperature = createTemperature();
		program3.add(temperature);
		
		//新建一个传感器分区（湿度），添加到节目3
		YQSensor humidity = createHumidity();
		program3.add(humidity);
		
		//新建一个计时分区，添加到节目3
		YQCount count = createCount();
		program3.add(count);
		
		//新建农历时间区，添加到节目3
		YQLunar lunar = createLunar();
		program3.add(lunar);
		
		list.add(program3);
		
		//发送节目会生成节目文件，指定节目文件的存放路径
		String dirPath = "D:/test";
		//创建客户端屏幕
		YQScreenClient screen = new YQScreenClient(ipAddr);
		
		//发送节目
		//监听器用于监听发送进度及状态
		//transferred实际发送的字节数,totalSize节目文件的总大小字节数
		//当控制器上已经存在部分文件时不再发送这部分文件，所以发送成功时transferred不一定等于totalSize
		screen.sendProgram(list, dirPath, new YQCmdListener() {
			
			@Override
			public void onProgress(int percent, long transferred, long totalSize) {
				print("percent = " + percent + " transferred = " + transferred + " tatalSize =" + totalSize);
			}
			
			@Override
			public void onFinish(YQException exception) {
				if (exception != null) {
					print("error message = " + exception.getMessage() + " error code = " + exception.getErrorCode());
				}else{
					print("发送节目成功");
				}
			}
		});
		
	}

	/**
	 * 新建农历时间区
	 * @return
	 */
	private static YQLunar createLunar() {
		//新建农历时间区
		YQLunar lunar = new YQLunar(0, 128, 128, 96);
		//以下设置非必须，不设置则采用默认值
//		//设置时差类型
//		lunar.setTimeDiffFlag(1);
//		//设置时差小时
//		lunar.setTimeDiffHour(2);
//		//设置时差分钟
//		lunar.setTimeDiffMin(0);
		
		//设置是否显示固定文字
		lunar.setFixedTextEnable(true);
		//设置固定文字颜色
		lunar.setFixedTextColor(0xff0000);
		//设置固定为
		lunar.setFixedText("农历日期");
		//设置多行显示
		lunar.setSingleLine(false);
		//设置字体名称
		lunar.setFontName("楷体");
		//设置字体大小
		lunar.setFontSize(16);
		
		//设置显示日期农历年
		lunar.setYearEnable(true);
		//设置农历年的颜色
		lunar.setYearColor(0xff0000);
		
		//设置显示农历月份和日
		lunar.setDateEnable(true);
		//设置月份的颜色
		lunar.setDateColor(0xff0000);
		
		//设置显示农历节日
		lunar.setFestivalEnable(true);
		//设置农历节日颜色
		lunar.setFestivalColor(0xff0000);
		
		return lunar;
	}
	/**
	 * 创建一个节目
	 * @return
	 */
	public static YQProgram createProgram(){
		//创建一个节目，其中384,384为节目的宽高，应该和屏幕的宽高相同
		//请注意时间的格式
		YQProgram program = new YQProgram(800, 600);
		//设置节目的开始日期，默认为一直播放
		program.setAgingStartDate("2015-12-30")
		//设置节目的结束日期，默认一直播放
		.setAgingStopDate("2017-12-30")
		//设置节目的开始时间，默认全天播放
		.setPeriodOnTime("08:00:00")
		//设置节目的结束时间，默认全天播放
		.setPeriodOffTime("23:00:00")
		//播放模式 0-按时长播放，1-按次播放。默认为按次播放
		.setPlayMode(1)
		//播放时长s/次数，默认播放一次
		.setPlayTime(1)
		//播放星期属性。其中bit0-bit6依次表示星期一致星期天 如b00000001 表示星期一播放，127表示忽略星期限制
		.setPlayWeek(127);
		
		return program;
	}
	/**
	 * 新建一个表盘区
	 * @return
	 */
	public static YQClock createClock(){
		//创建一个表盘区
		YQClock clock = new YQClock(0, 0, 128, 128);
		
		//设置字体,以下设置非必须，有默认值
		clock.setFontName("宋体");
		//设置字体大小
		clock.setFontSize(14);
		//设置显示固定文字
		clock.setFixedTextEnable(true);
		//设置固定文字的颜色，红色
		clock.setFixedTextColor(0xff0000);
		//设置固定文字
		clock.setFixedText("上海");
		
		//设置是否显示日期
		clock.setDateEnable(false);
		//设置日期颜色
		clock.setDateColor(0xff0000);
		//设置日期格式
		clock.setDateFormat(DateFormat.FORMAT1);
		//设置是否显示星期
		clock.setWeekEnable(true);
		//设置星期颜色
		clock.setWeekColor(0xff0000);
		//设置星期格式
		clock.setWeekFormat(WeekFormat.FORMAT1);
		
		//设置时针颜色
		clock.setHourHandColor(0xFFFFFF00);
		
		//设置分针颜色
		clock.setMinHandColor(0xFF00FF00);
		
		//设置秒针颜色
		clock.setSecondHandColor(0xFFFF0000);
		
		return clock;
	}
	private static YQCount createCount() {
		//新建计时分区
		YQCount count = new YQCount(128, 0, 140, 96, 12, "2016-12-30", "23:00:00", true, true, true, true);
		//设置时间颜色,以下设置非必须
		count.setCountColor(0xff0000)
		//设置固定文字使能
		.setFixedTextEnable(true)
		//设置固定文字颜色
		.setFixedTextColor(0xff0000)
		//设置固定文字
		.setFixedText("目标时间")
		//设置显示多行
		.setSingleLine(false)
		
		//设置天修饰符
		.setDayStr("天")
		//设置小时修饰符
		.setHourStr("小时")
		//设置分钟修饰符
		.setMinuteStr("分")
		//设置秒修饰符
		.setSecondStr("秒");
		
		return count;
	}
	/**
	 * 创建一个传感器分区，湿度
	 * @return
	 */
	private static YQSensor createHumidity() {
		//创建一个湿度分区，SHT11传感器接口1
		YQSensor sensor = new YQSensor(0, 20, 100, 20, YQSensorParitionType.HUMIDITY, YQSensorType.TEMPERATURE_HUMIDITY_PORT1);
		//设置单位为%RH
		sensor.setSensorUnit(YQSensorUnit.HUMIDITY)
		//设置显示固定文字
		.setFixedTextEnable(true)
		//设置固定文字
		.setFixedText("湿度：")
		//设置字体
		.setFontName("宋体")
		//设置字体大小
		.setFontSize(14)
		//设置正常显示颜色,绿色
		.setNormalColor(0xff00)
		//设置小数点 位数
		.setPointNum(1)
		//设置修正系数
		.setCoefficient(0)
		//设置报警条件，大于报警值
		.setWarnCondition(0)
		//设置报警值
		.setWarnValue(50)
		//设置报警值颜色
		.setWarnColor(0xff0000);
		
		return sensor;
	}
	
	/**
	 * 创建一个传感器分区，温度
	 * @return
	 */
	private static YQSensor createTemperature() {
		//注：传感器分区需要外接多功能板和传感器才能正常工作
		//新建一个温度传感器区，使用DS18B20传感器
		YQSensor sensor = new YQSensor(0, 0, 100, 20, YQSensorParitionType.TEMPERATURE, YQSensorType.TEMPERATURE_PORT1);
		
		//设置单位为℃
		sensor.setSensorUnit(YQSensorUnit.CENTIGRADE)
		//设置显示固定文字
		.setFixedTextEnable(true)
		//设置固定文字
		.setFixedText("温度：")
		//设置字体
		.setFontName("宋体")
		//设置字体大小
		.setFontSize(14)
		//设置正常显示颜色,绿色
		.setNormalColor(0xff00)
		//设置小数点 位数
		.setPointNum(1)
		//设置修正系数
		.setCoefficient(0)
		//设置报警条件，大于报警值
		.setWarnCondition(0)
		//设置报警值
		.setWarnValue(19)
		//设置报警值颜色
		.setWarnColor(0xff0000);
		
		return sensor;
	}
	
	
	/**
	 * 创建一个时间区
	 * @return
	 */
	public static YQTime createTime(){
		//创建一个时间区，坐标为0,20，宽度为128，高度为96
		YQTime time  = new YQTime(0, 0, 128, 96);
		//设置时差类型
//		time.setTimeDiffFlag(1);
//		//设置时差小时
//		time.setTimeDiffHour(2);
//		//设置时差分钟
//		time.setTimeDiffMin(0);
	
		//多行显示
		time.setSingleLine(false);
		
		//使能固定文字
		time.setFixedTextEnable(true);
		//设置固定文字
		time.setFixedText("上海时间");
		//社会固定文字颜色,绿色
		time.setFixedTextColor(0xff00);
		
		//使能显示日期
		time.setDateEnable(true);
		//设置日期红色
		time.setDateColor(0xff0000);
		//设置日期格式 2000-12-30
		time.setDateFormat(DateFormat.FORMAT1);
		
		
		//使能显示时间
		time.setTimeEnable(true);
		//使能时间颜色，红色
		time.setTimeColor(0xff0000);
		//使能时间格式
		time.setTimeFormat(TimeFormat.FORMAT1);
		
		
		//使能星期
		time.setWeekEnable(true);
		//设置星期颜色
		time.setWeekColor(0xff);
		
		//设置字体名称
		time.setFontName("宋体");
		//设置字体大小
		time.setFontSize(14);
		
		
		return time;
	}
	
	/**
	 * 创建一个图片分区
	 * @return
	 */
	public static YQPicture createPicture(){
		//创建一个图片分区,添加两张图片到分区中
		YQPicture picture = new YQPicture(120, 0, 100, 200);
		//图片1
		YQPicUnit picUnit1= new YQPicUnit("C:/Users/Li/Desktop/测试图片/butterfly.jpg");
		
		//设置显示特技
		picUnit1.setDisplayEffects(YQDisplayEffect.CONTINUOUS_PUSH_LEFT);
		//设置显示速度1-16,1最快
		picUnit1.setDisplaySpeed(3);
		//
		for(int i = 0; i < 5; i++){
			YQPicUnit picUnit = new YQPicUnit("C:/Users/Li/Desktop/测试图片/butterfly.jpg");
			picUnit.setDisplayEffects(YQDisplayEffect.CONTINUOUS_PUSH_LEFT);
			picture.add(picUnit);
		}
		return picture;
		
	}
	/**
	 * 创建视频分区
	 * @return
	 */
	public static YQVideo createVideo(){
		//创建一个视频分区，坐标为（0,0），宽高为200, 
		//YQ5E除外的控制器只支持一个视频分区,YQ5E支持两个视频分区，但是不能重叠
		//一个视频分区可以有多个视频
		//视频源的码率过高控制器有可能不能播放
		//YQ1/YQ1-75/YQ2最高支持码率为2800Kbps， YQ3/YQ4/YQ2E最高为28000Kbps
		YQVideo video = new YQVideo(0, 0, 200, 200);
		
		//以下设置只有YQ5E支持
		
		//设置分区音量模式
		//0- 本分区不静音，音量由各视频元决定
		//1- 本分区静音
		//用于多视频区情况下各分区音量协调
		video.setVolumeMode(0);
		//播放类型：
		//0- 播放本地视频
		//1- 播放外部输入视频
		//2- 混合播放
		video.setVideoType(0);
		
		//创建视频文件,添加到视频分区
		YQVideoUnit videoUnit1 = new YQVideoUnit("E:/测试视频/mp4/256x128-531.mp4");
		//设置窗口缩放模式,默认按窗口比例缩放
		//缩放模式
		//0- 按原始比例进行缩放
		//1- 按窗口比例进行缩放
		videoUnit1.setScaleMode(1);
		video.add(videoUnit1);
		
		//创建第二个视频文件，添加到视频分区
		YQVideoUnit videoUnit2 = new YQVideoUnit("E:/测试视频/mp4/256x144-1220.mp4");
		video.add(videoUnit2);
		
		//创建第3个视频文件，添加到视频分区，采用外部视频源，只有YQ5E支持
//		YQVideoUnit videoUnit3 = new YQVideoUnit("");
//		//输入视频源（播放外部输入视频）：
//		//0- CVBS 输入
//		//1- HDMI 输入
//		videoUnit3.setSource(1);
//		video.add(videoUnit3);
		
		return video;
	}
	
	/**
	 * 创建文本分区
	 * @return
	 */
	public static YQText createText(){
		//创建文本分区
		YQText text = new YQText(0, 0, 128, 80);

		//创建一个文本
		YQTextUnit textUnit = new YQTextUnit("记者从铁路部门获悉，自2017年1月5日零时起，全国铁路将实施新的列车运行图。在此之前，为了配合运营图调整，2016年12月30日之后的火车票预售期由60天缩短至30天。");
		//设置为多行显示
		textUnit.setSingleLine(false)
		//设置字体名称
		.setFontName("楷体")
		//设置字体大小
		.setFontSize(16)
		//设置是否加粗
		.setIsBold(false)
		//设置是否斜体
		.setIsItalic(false)
		//设置字体颜色
		.setFontColor(0xff0000)
		//设置背景颜色,黑色
		.setBackColor(0xff000000)
		//设置显示特技
		.setDisplayEffects(YQDisplayEffect.NONE)
		//显示停留时间单位为秒，范围为0-255
		.setStayTime(5)
		//设置特技速度,1-16级，1级最快
		.setDisplaySpeed(4);
		text.add(textUnit);
		
		//创建文本2
		YQTextUnit textUnit2 = new YQTextUnit("上海仰邦科技股份总部位于中国著名的高科技产业集聚区——上海漕河泾新兴技术开发区，是专业从事LED应用技术研究的高新技术企业，LED控制系统专业制造商和主流供应商。上海市软件企业和上海市高新技术企业。");
		//设置为单行显示
		textUnit2.setSingleLine(true)
		//设置字体名称
		.setFontName("楷体")
		//设置字体大小
		.setFontSize(16)
		//设置是否加粗
		.setIsBold(false)
		//设置是否斜体
		.setIsItalic(false)
		//设置字体颜色
		.setFontColor(0xff0000)
		//设置背景颜色,透明色
		.setBackColor(0)
		//设置显示特技
		.setDisplayEffects(YQDisplayEffect.CONTINUOUS_PUSH_LEFT)
		//显示停留时间单位为秒，范围为0-255
		.setStayTime(0)
		//设置特技速度,1-16级，1级最快
		.setDisplaySpeed(4);
		text.add(textUnit2);
		
		return text;
	}
	
	private static void print(String string){
		System.out.println(string);
	}
	
}
