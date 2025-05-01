class HuffLeafNode
    def initialize(char, weight = nil)
        @char = char
        @weight = weight
    end
  
    def isLeaf
        return true
    end
    #getter functions
    def char
        @char
    end
  
    def weight
        @weight
    end

  #setter functions
    def set_weight(new_weight)
        @weight = new_weight
    end
  
    def set_char(new_char)
        @char = new_char
    end

  
end

class HuffInternalNode
    def initialize(char, left = nil, right = nil)
        @weight = weight
        @left = left 
        @right = right 
    end

    def isLeaf
        return false
    end
  
    #getter functions
    def weight
      @weight
    end
  
    def left
      @left
    end
  
    def right
      @right
    end

  #setter functions
    def set_left(new_left)
      @left = new_left
    end
  
    def set_right(new_right)
      @right = new_right
    end
  
    def set_weight(new_weight)
      @weight = new_weight
    end
  
    #
    def pretty_print(node = self, prefix = '', is_left = true)
      pretty_print(node.right, "#{prefix}#{is_left ? '│   ' : '    '}", false) if node.right
      puts "#{prefix}#{is_left ? '└── ' : '┌── '}#{node.data ? node.data : "nil"}"
      pretty_print(node.left, "#{prefix}#{is_left ? '    ' : '│   '}", true) if node.left
    end
  #
end

class HuffTree
    #currently can't have root node as leaf
    @root = HuffInternalNode.new(nil)

    #need build_tree method. need to take in in array and start building from ground up
end