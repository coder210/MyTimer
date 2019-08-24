local button = require "button"
local myWidget = require "mywidget"


local MyButton = myWidget:new()

function MyButton:setId()
	self.id = button.newButton();
end

function MyButton:setText(text)
	button.setText(self.id, text)
end

function MyButton:getText()
	return button.getText(self.id)
end

function MyButton:setClickEvent(funcName)
	button.setClickEvent(self.id, funcName);
end

return MyButton;



