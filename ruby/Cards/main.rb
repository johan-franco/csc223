#brings card class
require_relative 'Card'  

#testing functionality
card = Card.new(1, 2)  

puts "#{card.to_string}"

card2 = Card.new(3, 13)  
puts "#{card2.to_string}"  

card3 = Card.new(0, 0)  
puts "#{card3.to_string}" 

#test overload of ==
samecard = Card.new(1, 2)  

puts "#{samecard == card}"