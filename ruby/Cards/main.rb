require_relative 'Card'  

card = Card.new(1, 2)  

puts card.to_string  

card2 = Card.new(3, 13)  
puts "#{card2.to_string}"  

card3 = Card.new(0, 0)  
puts card3.to_string 
