local mybutton = require("mybutton")
local mylabel = require("mylabel")
local mywidget = require("mywidget")
local myanimation = require("myanimation")
local qt = require("qt")

-- 半径
local r = 200

-- 按钮大小
local btnSize = {
	w = 50,
	h = 50
}

-- 面板大小
local panelSize = {
	w = 100,
	h = 100
}

-- 设置动画
local goAnimate = {}
local backAnimat = {}

local go = true;


function btn2Click()
	qt.debug("lua btn2Click call")
end

function btn3Click()
	qt.debug("lua btn3Click call")
end

-- panel双击事件
function panelDbClick()
	if go then
		for i = 1, #goAnimate, 1 do
			goAnimate[i]:start()
		end
	else
		for i = 1, #goAnimate, 1 do
			backAnimat[i]:start()
		end
	end
	go = not go
end

function start(parentId)

	-- 设置窗口大小
	local widget = mywidget:new();
	widget:setId(parentId);
	widget:setFixedSize(r * 2 + btnSize.w, r * 2 + btnSize.h);
	
	
	-- 创建panel
	local panel = mylabel:new();
	panel:setId()
	panel:setText("确定");
	panel:setFixedSize(panelSize.w, panelSize.h);
	panel:setTextCenter();
	panel:setStyleSheet("QLabel{background-color:#333333;color:#eee;font-size:20px;font-weight:bold;border-radius:10px;}");
	panel:move((widget:getWidth() - panel:getWidth()) / 2, (widget:getHeight() - panel:getHeight()) / 2);
	
	
	-- btn起始坐标
	local btnStartX = (widget:getWidth() - btnSize.w) / 2;
	local btnStartY = (widget:getHeight() - btnSize.h) / 2;
	
	
	-- 创建button
	local btnArray = {};
	
	btnArray[1] = mybutton:new();
	btnArray[1]:setId();
	btnArray[1]:setText("开始");
	btnArray[1]:setFixedSize(btnSize.w, btnSize.h);
	btnArray[1]:setStyleSheet("QPushButton{ background-color:#333333; color: #ccc; font-size: 12px; border-radius: 25px; }");
	btnArray[1]:move(btnStartX, btnStartY);
	btnArray[1]:setParent(parentId);
	
	
	btnArray[2] = mybutton:new();
	btnArray[2]:setId();
	btnArray[2]:setText("暂停");
	btnArray[2]:setFixedSize(btnSize.w, btnSize.h);
	btnArray[2]:setStyleSheet("QPushButton{ background-color:#333333; color: #ccc; font-size: 12px; border-radius: 25px; }");
	btnArray[2]:move(btnStartX, btnStartY);
	btnArray[2]:setClickEvent("btn2Click");
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
	toPostions[1] = getTargetPostion(btnStartX, btnStartY, 30, r);
	toPostions[2] = getTargetPostion(btnStartX, btnStartY, 60, r);
	toPostions[3] = getTargetPostion(btnStartX, btnStartY, 90, r);

	
	for k = 1, #btnArray, 1 do
		
		goAnimate[k] = myanimation:newAnimation()
		
		--qt.debug("x=" .. toPostions[k].x .. "y=" .. toPostions[k].y .. "id = " .. goAnimate[k]:getId() .. "|btnid = " .. btnArray[k]:getId())
		
		goAnimate[k]:setTargetObject(btnArray[k]:getId())
		goAnimate[k]:setPropertyName("pos")
		goAnimate[k]:setDuration(100 * k)
		goAnimate[k]:setStartValue(btnStartX, btnStartY)
		goAnimate[k]:setEndValue(toPostions[k].x, toPostions[k].y)
		
		
		backAnimat[k] = myanimation:newAnimation()
		backAnimat[k]:setTargetObject(btnArray[k]:getId())
		backAnimat[k]:setPropertyName("pos")
		backAnimat[k]:setDuration(100* k)
		backAnimat[k]:setStartValue(toPostions[k].x, toPostions[k].y)
		backAnimat[k]:setEndValue(btnStartX, btnStartY)
	end
	
	
	return 1;
end


-- 获取到目标坐标
-- startX: x轴起始点
-- startY: y轴起始点
-- ang: 角度
-- r: 半径
-- 返回目标点坐标
function getTargetPostion(startX, startY, ang, r)
	local cosValue = math.cos(ang * degree());
	local disX = cosValue * r;
	
	local sinValue = math.sin(ang * degree());
	local disY = sinValue * r;

	return { 
		x = (startX + disX), 
		y = (startY + disY)
	};
end


-- 角度转弧度
function degree()
    return math.pi / 180;
end
