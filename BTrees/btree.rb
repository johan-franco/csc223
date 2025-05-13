class RootNode
    def initialize
        @maxval = 4
        @values = []
        @paths = {}
    end

    def isRoot
        return true
    end

end

class Node < RootNode
    def initialize
        super
        @minval = @maxval/2
    end

    def isRoot
        return false
    end

end

class BTree
    def initialize
        @root
    end

end