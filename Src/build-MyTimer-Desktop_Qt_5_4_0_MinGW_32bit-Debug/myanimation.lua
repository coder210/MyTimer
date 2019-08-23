local animation = require("animation")

local MyAnimation = {
	id = 0
}

function MyAnimation:newAnimation(o)
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	o.id = animation.newPropertyAnimation() -- 这里一定要用o,不能用self
	return o
end

function MyAnimation:getId()
	return self.id;
end

function MyAnimation:setTargetObject(obj)
	animation.setTargetObject(self.id, obj)
end

function MyAnimation:setPropertyName(name)
	animation.setPropertyName(self.id, name)
end

function MyAnimation:setDuration(duration)
	animation.setDuration(self.id, duration)
end

function MyAnimation:setStartValue(x, y)
	animation.setStartValue(self.id, x, y)
end

function MyAnimation:setEndValue(x, y)
	animation.setEndValue(self.id, x, y)
end

function MyAnimation:start()
	animation.start(self.id)
end

return MyAnimation


