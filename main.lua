BUTTON_HEIGHT = 64
function newButton(text, fn)
  return{
    text = text,
    fn = fn,
    now = false,
    last = false
  }
end
local buttons = {}
local font = nil

function love.load()
  font = love.graphics.newFont(32)
  player = {}
  player.x = 0
  player.y = 500
  
  startmenu = true
  
  table.insert(buttons, newButton(
      "Start Game",
      function()
        startmenu = false
      end))
  table.insert(buttons, newButton(
      "Load Game",
      function()
        print("Load")
      end))
  table.insert(buttons, newButton(
      "Exit",
      function()
        love.event.quit(0)
      end))
  end
  function love.update(dt)
  if love.keyboard.isDown("right") then
    player.x = player.x + 1
  elseif love.keyboard.isDown("left") then
    player.x = player.x -1
  end
  if love.keyboard.isDown("up") then
    player.y = player.y - 1
  elseif love.keyboard.isDown("down") then
    player.y = player.y + 1 
      
  end
  
end
  
  function love.draw()
    if startmenu == true then
      local ww = love.graphics.getWidth()
      local wh = love.graphics.getHeight()
      
      local button_width = ww * (1/3)
      local margin = 16
      local total_height = (BUTTON_HEIGHT + margin) * #buttons
      local cursor_y = 0
      
      for i, button in ipairs(buttons) do
        button.last = button.now
        local bx = (ww * 0.5) - (button_width * 0.5)
        local by = (wh * 0.5) - (total_height * 0.5) + cursor_y
        local color = {0.4,0.4,0.5,1.0}
        local mx,my = love.mouse.getPosition()
        local hot = mx > bx and mx < bx + button_width and
                    my > by and my < by + BUTTON_HEIGHT
                    
        if hot then
          color = {0.8,0.8,0.9,1.0}
        end
        
        button.now = love.mouse.isDown(1)
        if button.now and not button.last and hot then
          button.fn()
        end
                    
        love.graphics.setColor(unpack(color))
        love.graphics.rectangle( "fill",bx,by,button_width,BUTTON_HEIGHT)
        
        love.graphics.setColor(0,0,0,1)
        local textW = font:getWidth(button.text)
        local textH = font:getHeight(button.text)
        
        love.graphics.print(button.text,font,(ww*0.5)-(textW*0.5),by+textH*0.5)
        
          
          cursor_y = cursor_y + (BUTTON_HEIGHT + margin)
        end
    else
      love.graphics.setColor(0,255,0)
      love.graphics.rectangle("fill", player.x, player.y, 40, 80)
    end
  end
  
  