class HuffInternalNode
    attr_accessor :left, :right, :weight

    def initialize(weight, left = nil, right = nil)
        @weight = weight
        @left = left 
        @right = right 
    end

    def isLeaf
        return false
    end

    def to_s
        message = "#{@weight}"
        return message
    end

end

class HuffLeafNode < HuffInternalNode
    attr_accessor :char, :weight
    def initialize(char, weight = nil)
        super(weight)
        @char = char
    end
  
    def isLeaf
        return true
    end

    def to_s
        message = super
        message += "#{@char}"
        return message
    end


end

class HuffTree
    attr_reader :root

    def initialize(frequency)
        @leaf_nodes = frequency
        @root = build_tree(@leaf_nodes)
        @code = {}

    end
    
    def print_tree(node, left_accessor: nil, right_accessor: nil, value_accessor: nil, prefix: "", is_left: true)
        return if node.nil? 
        

        left_accessor  ||= -> (n) { n.left }
        right_accessor ||= -> (n) { n.right }
        value_accessor ||= -> (n) { n.to_s }
      
        right_child = right_accessor.call(node)
        left_child  = left_accessor.call(node)
      
        print_tree(right_child, left_accessor: left_accessor, right_accessor: right_accessor,
                   value_accessor: value_accessor,
                   prefix: prefix + (is_left ? "│   " : "    "), is_left: false)
      
        puts prefix + (is_left ? "└── " : "┌── ") + value_accessor.call(node)
      
        print_tree(left_child, left_accessor: left_accessor, right_accessor: right_accessor,
                   value_accessor: value_accessor,
                   prefix: prefix + (is_left ? "    " : "│   "), is_left: true)
    end

    def build_tree(chawei)
        #transform all of input array elements into leaf nodes
        nodes = chawei.map { |char, weight| HuffLeafNode.new(char,weight) }
        
        while nodes.size != 1
            #sort array of leaf nodes by weight to build from the ground up ()
            nodes = nodes.sort_by { |node| node.weight }

            #take the first element in array and assign to left as it should have the lowest weight
            left = nodes.shift
            right = nodes.shift

            internal_weight = left.weight + right.weight

            internal = HuffInternalNode.new(internal_weight, left,right)
            
            #put internal node back into array, this will loop until only root element is left
            nodes << internal
        end

        return nodes.first
    end

    def insert(leaf_node)
        @leaf_nodes << leaf_node
        @root = build_tree(@leaf_nodes)
    end

    def decode(input)
        trav = @root
        message = ""
        input.each_char do |bit|
            if bit == '0'
                trav = trav.left
            else
                trav = trav.right
            end

            if trav.isLeaf == true
                message << trav.char
                trav = @root
            end
        end
        return message
    end

    def encode(text)
        codes = generate_codes
        
        encoded = text.chars.map do |char|
            codes[char] 
        end.join
        
        return encoded
    end
    
    def generate_codes
        codes = {}
        # Start traversal from root with empty path
        traverse_for_codes(@root, "", codes)
        codes
    end
    
    def traverse_for_codes(node, current_path, codes)
        if node.isLeaf
          # Record the character's code when we reach a leaf
            codes[node.char] = current_path unless node.char.nil?
        else
          # Recursively traverse left (0) and right (1)
            traverse_for_codes(node.left, current_path + "0", codes)
            traverse_for_codes(node.right, current_path + "1", codes)
        end
    end


end

test_frequencies = [
    ['a', 5],
    ['b', 9],
    ['c', 12],
    ['d', 13],
    ['e', 16],
    ['f', 45]
]

#need to work on pretty print
tree = HuffTree.new(test_frequencies)
puts "\nTree structure:"

# testing root weight
expected_root_weight = test_frequencies.sum { |char, weight| weight }
actual_root_weight = tree.root.weight
puts "\nVerification:"
puts "Expected root weight: #{expected_root_weight}"
puts "Actual root weight:   #{actual_root_weight}"


test_string = "abcdef"
encoded = tree.encode(test_string)
decoded = tree.decode(encoded)
puts "\nMessage:'#{test_string}'"
puts "Encoded: #{encoded}"
puts "Decoded: #{decoded}"

test_string = "abcdef"
encoded = tree.encode(test_string)
decoded = tree.decode(encoded)
puts "\n Message: '#{test_string}'"
puts "Encoded: #{encoded}"
puts "Decoded: #{decoded}"

test_char = "a"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"  

test_char = "b"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"  

test_char = "c"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"  

test_char = "d"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"

test_char = "e"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"

test_char = "f"
encoded = tree.encode(test_char)
puts "\n Single character '#{test_char}'"
puts "Encoded: #{encoded}"

tree.print_tree(tree.root)