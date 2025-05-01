class HuffLeafNode
    def initialize(element, weight = nil)
        @char = element
        @weight = 
    end
  
    #getter functions
    def data
      @data
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
  
    def set_data(new_data)
      @data = new_data
    end
  
    #method to print node
    def pretty_print(node = self, prefix = '', is_left = true)
      pretty_print(node.right, "#{prefix}#{is_left ? '│   ' : '    '}", false) if node.right
      puts "#{prefix}#{is_left ? '└── ' : '┌── '}#{node.data ? node.data : "nil"}"
      pretty_print(node.left, "#{prefix}#{is_left ? '    ' : '│   '}", true) if node.left
    end
  
end

class HuffInternalNode
    def initialize(data, left = nil, right = nil)
      @data = data
      @left = left #tree child that is smaller than data
      @right = right #tree child that is greater than data
    end
  
    #getter functions
    def data
      @data
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
  
    def set_data(new_data)
      @data = new_data
    end
  
    #method to print node
    def pretty_print(node = self, prefix = '', is_left = true)
      pretty_print(node.right, "#{prefix}#{is_left ? '│   ' : '    '}", false) if node.right
      puts "#{prefix}#{is_left ? '└── ' : '┌── '}#{node.data ? node.data : "nil"}"
      pretty_print(node.left, "#{prefix}#{is_left ? '    ' : '│   '}", true) if node.left
    end
  
  end