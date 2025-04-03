class Card #unlike C++ classes aren't automatically private so we can use classes instead of structs
    attr_accessor :suit, :rank #to generate commands to grab info

    def initialize(s,r) #can;t have mult initializers
        #apparently using @@ means that all cards have the same values across all instances
        #previously i used it because i thought it would be necessary for the other classes like deck.
        if s == nil && r == nil
            @suit = 0
            @rank = 0
        
        else
            @suit = s
            @rank = r
        end
    end

    def to_string()
        @suit_strings = ["None", "Clubs", "Diamonds",
        "Hearts", "Spades"]

        @rank_strings = ["Joker", "Ace", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "Jack", "Queen", "King"]
        #if rank == 0 then return joker else return to_string ver of card
        return @rank == 0 ? @rank_strings[@rank] : @rank_strings[@rank] + " of " + @suit_strings[@suit]
    end

    def ==(other_card)
        #the more simple way I kept trying to do wasn't working but this does
        if @rank != other_card.rank  or @suit != other_card.suit
            return false
        end
        return true
    end

    def >(other_card)
        #nil is so that it can continue to be evaluated 
        #without any parentheses an error will occur as intepreter will be expecting : instead of "true"
        @suit > other_card.suit ? (return true)  :  nil
        
        other_card.suit > @suit ? (return false) : nil

        @rank > other_card.rank ? (return true ): nil

        other_card.rank > @rank ? (return false ): nil
        return false
    end

    def <(other_card)
        #self is how we reference the onject itself
        return !(self > (other_card) || self == other_card);
    end
end

class Deck
    attr_reader :cards #need this to able to use get .suit .rank etc
    def initialize(num)
        #creates deck of cards that are all unique
        @cards = Array.new(num) { Card.new(nil, nil) } #@cards = Array.new(num, Card.new(nil, nil))   
    end
  
    def set()
      if @cards.size == 52
        i = 0
        (1..4).each do |s|  
          (1..13).each do |r| 
            @cards[i].suit = s
            @cards[i].rank = r
            i += 1  
          end
        end
      else
        puts "Deck must have exactly 52 cards to use set()."
      end
    end

    def shuffle
        @cards.each_index do |i|
            rand_card = rand(@cards.size)  # Random index between 0 and cards.size-1
            @cards[i], @cards[rand_card] = @cards[rand_card], @cards[i]  # Swap cards through changing values at the same time
        end
    end
end