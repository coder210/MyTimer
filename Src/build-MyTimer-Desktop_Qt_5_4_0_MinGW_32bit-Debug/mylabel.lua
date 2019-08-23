local label = require "label"
local myWidget = require "mywidget"


local MyLabel = myWidget:new()

function MyLabel:setId()
	MyLabel.id = label.newLabel()
end


function MyLabel:setText(text)
	label.setText(MyLabel.id, text)
end

function MyLabel:setTextCenter()
	label.setTextCenter(MyLabel.id)
end

function MyLabel:setDbClicked(funcName)
	label.setDbClicked(MyLabel.id, funcName)
end


return MyLabel