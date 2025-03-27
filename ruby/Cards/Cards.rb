class Card
    attr_accessor :suit, :rank

    @@suit
    @@rank
    def initialize()
        @@suit = 0
        @@rank = 0
    def initialize(s,r)
        @@suit = s
        @@rank = r
end