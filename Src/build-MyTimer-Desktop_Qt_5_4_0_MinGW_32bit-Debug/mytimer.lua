local mybutton = require("mybutton")
local mylabel = require("mylabel")
local mywidget = require("mywidget")
local myanimation = require("myanimation")
local qt = require("qt")
local qttimer = require("qttimer")

-- 半径
local r = 250

-- 按钮大小
local btnSize = {
	w = 50,
	h = 50
}

-- 面板大小
local panelSize = {
	w = 80,
	h = 80
}

-- 设置动画
local goAnimate = {}
local backAnimat = {}

local go = true;

local timerSpan = 0;


-------------------------------------控件开始-----------------------------------------------------

local qtTimer = nil;
local panel = nil;
-- 1: 开始
local btnArray = {};

-------------------------------------控件结束-----------------------------------------------------


------------------------------------事件开始----------------------------------------------
function triggerTimer()
	if qtTimer then
		local txt = btnArray[1]:getText()
		qt.debug(txt)
		if txt == "开始" then
			qtTimer:start(1000)
			btnArray[1]:setText("暂停")
		else
			qtTimer:stop()
			btnArray[1]:setText("开始")
		end
			
	end
end

function stop()
	if qtTimer then
		--qtTimer:stop()
	end
end

function btn3Click()
	qt.debug("lua btn3Click call")
end

function timerOutEvent()
	timerSpan = timerSpan + 1;
	if panel then
		local datetimeStr = qt.timeSpan2Datetime(timerSpan)
		panel:setText(datetimeStr)
	end
end

-- panel双击事件
function panelDbClick()
	if go then
		for i = 1, #goAnimate, 1 do
			goAnimate[i]:start()
		end
	else
		for i = 1, #backAnimat, 1 do
			backAnimat[i]:start()
		end
	end
	go = not go
end

---------------------------------------事件结束-------------------------------------------

function start(parentId)

	-- 设置窗口大小
	local widget = mywidget:new();
	widget:setId(parentId);
	widget:setFixedSize(r * 2 + btnSize.w, r * 2 + btnSize.h);
	
	
	-- 创建panel
	panel = mylabel:new();
	panel:setId()
	panel:setText("00:00:00");
	panel:setFixedSize(panelSize.w, panelSize.h);
	panel:setTextCenter();
	panel:setStyleSheet("QLabel{background-color:#333333;color:#eee;font-size:14px;font-weight:bold;border-radius:20px;}");
	panel:move((widget:getWidth() - panel:getWidth()) / 2, (widget:getHeight() - panel:getHeight()) / 2);
	
	
	-- btn起始坐标
	local btnStartX = (widget:getWidth() - btnSize.w) / 2;
	local btnStartY = (widget:getHeight() - btnSize.h) / 2;
	
	
	btnArray[1] = mybutton:new();
	btnArray[1]:setId();
	btnArray[1]:setText("开始");
	btnArray[1]:setFixedSize(btnSize.w, btnSize.h);
	btnArray[1]:setStyleSheet("QPushButton{ background-color:#333333; color: #ccc; font-size: 12px; border-radius: 25px; }");
	btnArray[1]:move(btnStartX, btnStartY);
	btnArray[1]:setParent(parentId);
	btnArray[1]:setClickEvent("triggerTimer");
	
	btnArray[2] = mybutton:new();
	btnArray[2]:setId();
	btnArray[2]:setText("暂停");
	btnArray[2]:setFixedSize(btnSize.w, btnSize.h);
	btnArray[2]:setStyleSheet("QPushButton{ background-color:#333333; color: #ccc; font-size: 12px; border-radius: 25px; }");
	btnArray[2]:move(btnStartX, btnStartY);
	btnArray[2]:setClickEvent("stop");
	btnArray[2]:setParent(parentId);
	
	
	btnArray[3] = mybutton:new();
	btnArray[3]:setId();
	btnArray[3]:setText("保存");
	btnArray[3]:setFixedSize(btnSize.w, btnSize.h);
	btnArray[3]:setStyleSheet("QPushButton{ background-color:#333333; color: #ccc; font-size: 12px; border-radius: 25px; }");
	btnArray[3]:move(btnStartX, btnStartY);
	btnArray[3]:setParent(parentId);
	btnArray[3]:setClickEvent("btn3Click");
	
	panel:setParent(parentId);
	panel:setDbClicked("panelDbClick");
	
	-- 设置坐标
	local toPostions = {}
	toPostions[1] = qt.getTargetPostion(btnStartX, btnStartY, 120, r);
	toPostions[2] = qt.getTargetPostion(btnStartX, btnStartY, 150, r);
	toPostions[3] = qt.getTargetPostion(btnStartX, btnStartY, 180, r);

	
	for k = 1, #btnArray, 1 do
		
		goAnimate[k] = myanimation:newAnimation()
		
		qt.debug("x=" .. toPostions[k].x .. "y=" .. toPostions[k].y .. "id = " .. goAnimate[k]:getId() .. "|btnid = " .. btnArray[k]:getId())
		
		goAnimate[k]:setTargetObject(btnArray[k]:getId())
		goAnimate[k]:setPropertyName("pos")
		goAnimate[k]:setDuration(100 * k)
		goAnimate[k]:setStartValue(btnStartX, btnStartY)
		goAnimate[k]:setEndValue(toPostions[k].x, toPostions[k].y)
		
		
		backAnimat[k] = myanimation:newAnimation()
		backAnimat[k]:setTargetObject(btnArray[k]:getId())
		backAnimat[k]:setPropertyName("pos")
		backAnimat[k]:setDuration(100 * k)
		backAnimat[k]:setStartValue(toPostions[k].x, toPostions[k].y)
		backAnimat[k]:setEndValue(btnStartX, btnStartY)
	end
	
	
	-- 设置定时器
	qtTimer = qttimer:new()
	qtTimer:setId()
	qtTimer:setTimeoutEvent("timerOutEvent")
	qtTimer:setParent(parentId)
	
	
	
	return 1;
end
