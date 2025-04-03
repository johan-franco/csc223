require_relative 'Card'  

#currently im just trying to create a single player version of it
class Blackjack
    def initialize
        @deck = Deck.new(52)
        @deck.set
        @deck.shuffle
        @player_hand = []
        @player_number_cards = 0
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

        @player_number_cards +=2
         
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
        puts "Your Current Hand: \n"
        (0..(@player_number_cards-1)).each do |r| 
            puts "#{@player_hand[r].to_string()}"
        end
        puts "Score: #{@player_score}\n\n"
        #recieve input on whether or not to deal or not to deal
        puts "Hit or Stand?"
        decision = gets.chomp()
        #recieve whether or not they want to play again
        case decision
        when "Hit" or "hit"
            @player_hand << @deck.cards.pop
            @player_score = self.calculate_score(@player_hand)
            @player_number_cards +=1

            if @player_score > 21 
                self.endgame()
            else
                self.play_round()
        when "Stand" or "stand"
            self.endgame()
    end

    def endgame
        nil
        #output how you won or lost
        # potentially reset vars so new game can be initialized
    end
end

game = Blackjack.new()
game.start_game