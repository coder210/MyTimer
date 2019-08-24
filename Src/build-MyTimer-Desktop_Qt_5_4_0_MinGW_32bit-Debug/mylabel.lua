local label = require "label"
local myWidget = require "mywidget"


local MyLabel = myWidget:new()

function MyLabel:setId()
	MyLabel.id = label.newLabel()
end


function MyLabel:setText(text)
	label.setText(self.id, text)
end

function MyLabel:setTextCenter()
	label.setTextCenter(self.id)
end

function MyLabel:setDbClicked(funcName)
	label.setDbClicked(self.id, funcName)
end


return MyLabel