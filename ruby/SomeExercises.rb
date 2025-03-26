#Exercises listed to do in Odin
First = "Johan"
Second = "Franco Campos"

#print names using string interpolation
puts "#{First} " + "#{Second}"

#print years using hash 
movies = { :endgame => 2019, :spiritedaway => 2002, :lookback => 2024}

puts movies[:endgame]
puts movies[:spiritedaway]
puts movies[:lookback]

#print years using array
year_array = [2019,2002,2024]

year_array.each do |year|
    puts year
  end
  