class RootNode
    attr_accessor :maxval, :values, :paths
    def initialize()
        @maxval = 4
        @values = []
        @paths = []
    end

    def isRoot
        return true
    end

    def insert(val)
        if @values.length() == @maxval
            @values.insert(val)
            @values.sort!
            if paths.empty
                paths[0] = Node.new(@values.slice(0,1))
                paths[1] = Node.new(@values.slice(3,4))


            else
                #do something else
                return
            end
            return
        else 
            @values.insert(val)
            @values.sort!
            update_paths()
        end
    
    end

    def update_paths
        return
    end

end

class Node < RootNode
    attr_accessor :minval
    def initialize(val = nil)
        super
        @values = val
        @minval = @maxval/2
    end

    def isRoot
        return false
    end

end

class BTree
    attr_reader :root
    def initialize
        @root = RootNode.new()
    end

    def insert(val)
        traverse(val).insert(val)
    end
    
    def traverse(val)
        if @roots.path.empty
            return @root
        else
            #traverse using val
        end
    end
end