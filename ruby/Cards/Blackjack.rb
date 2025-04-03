require_relative 'Card'  

#currently im just trying to create a single player version of it
class Blackjack
    def initialize
        @deck = Deck.new(52)
        @deck.set
        @deck.shuffle
        @player_hand = []
        @player_score = 0
        #@dealer_hand
        #@dealer_score
    end
    
    def start_game
        puts "Starting Game\n\n"
        puts "Try to get as close to 21 without going over.\n\n"
        
        # Deal initial 2 cards (from the front of deck) and adds it to the hand
        2.times { @player_hand << @deck.cards.pop }
        @player_score = calculate_score(@player_hand)

        (0..1).each do |r| 
            puts "#{@player_hand[r].to_string()}"
        end
    
        self.play_round()
    end
    
    
    def calculate_score(hand)
        score = 0
        aces = 0
    
        hand.each do |card|
            case card.rank
            when 1 # Ace
                score += 11
                aces += 1
            when 11..13 # Face cards
                score += 10
            else
                score += card.rank
            end
        end
    
        # Adjust for aces if score is over 21
        while score > 21 && aces > 0
            score -= 10
            aces -= 1
        end
    
        return score
    end

    def play_round
        #need to output hands
        #recieve input on whether or not to deal or not to deal
        #recieve whether or not they want to play again
        nil
    end

end

game = Blackjack.new()
game.start_game