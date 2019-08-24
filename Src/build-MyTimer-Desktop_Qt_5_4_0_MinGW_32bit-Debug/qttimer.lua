local timer = require("timer")

local QtTimer = {
	id = 0
}

function QtTimer:new(o)
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	return o
end

function QtTimer:setId()
	self.id = timer.newTimer()
end

function QtTimer:getId()
	return self.id;
end

function QtTimer:setTimeoutEvent(funcName)
	timer.setTimeoutEvent(self.id, funcName)
end

function QtTimer:start(msec)
	timer.start(self.id, msec)
end

function QtTimer:stop()
	timer.stop(self.id)
end


function QtTimer:setParent(parentId)
	timer.stop(self.id, parentId)
end

return QtTimer