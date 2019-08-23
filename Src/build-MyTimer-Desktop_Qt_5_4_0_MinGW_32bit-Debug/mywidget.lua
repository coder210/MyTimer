local widget = require("widget")

local MyWidget = {
	id = 0
}


function MyWidget:new(o)
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	return o
end

function MyWidget:setId(id)
	self.id = id;
end

function MyWidget:getId()
	return self.id;
end

function MyWidget:getWidth()
	return widget.getWidth(self.id)
end

function MyWidget:getHeight()
	return widget.getHeight(self.id)
end

function MyWidget:setFixedSize(w, h)
	widget.setFixedSize(self.id, w, h)
end

function MyWidget:setStyleSheet(styleSheet)
	widget.setStyleSheet(self.id, styleSheet)
end

function MyWidget:move(x, y)
	widget.move(self.id, x, y)
end

function MyWidget:setParent(parentId)
	widget.setParent(self.id, parentId);
end

return MyWidget