class Card #unlike C++ classes aren't automatically private so we can use classes instead of structs
    attr_accessor :suit, :rank #to generate commands to grab info

    def initialize(s,r) #can;t have mult initializers
        @@suit = s
        @@rank = r
    end

    def to_string
        @suit_strings = ["None", "Clubs", "Diamonds",
        "Hearts", "Spades"]

        @rank_strings = ["Joker", "Ace", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "Jack", "Queen",
        "King"]
        #if rank == 0 then return joker else return to_string ver of card
        return @@rank == 0 ? @rank_strings[@@rank] : @rank_strings[@@rank] + " of " + @suit_strings[@@suit]
    end
end