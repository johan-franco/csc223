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

puts "#{samecard > card}" 

puts "#{samecard > card2}" #should be true

puts "#{card2 > card3}" #false

puts "#{samecard < card2}" #should be false

puts "#{card2 < card3}" #true