# Huffman Coding Trees

## What is it?

So ASCII assigns each character a value of 8 bits. If this characters were to occur at the same frequency then this method of storing them would actually be the most efficient. However, if the frequency of each character does differ than it actually would be more efficient if the characters that are more frequent had a length of less than 8 bits. This would also mean that the less frequent characters would have a length of bits higher than 8. This is called variable-length codes and it is called Huffman coding (file compression).

The [Huffman Coding Tree](https://en.wikipedia.org/wiki/Huffman_coding) has leaf nodes representing the characters. The reason for representing this as a tree is because every parent node would have either a left or right node, these directions can be then represented as either a 0 or a 1. This allows us to represent characters in less than 8 bits and the less frequent characters in more than 8 bits. We are trying to build a tree with the minimum external path weight, which is the sum of the weighted length paths for the leaf nodes. The weighted length paths are specifically weight multipled depth.



```mermaid
graph TD
    Root[100] -->|0| f[45: f]
    Root -->|1| N55[55]
    N55 -->|0| N25[25]
    N55 -->|1| N30[30]
    N25 -->|0| c[12: c]
    N25 -->|1| d[13: d]
    N30 -->|0| N14[14]
    N30 -->|1| e[16: e]
    N14 -->|1| b[9: b]
    N14 -->|0| a[5: a]
```

| Char | Frequency | Code |
| - | ----- | ---- |
| a |  5    | 1100 |
| b |  9    | 1101 |
| c |  12   | 100  |
| d |  13   | 101  |
| e |  16   | 111  |
| f | 45    | 0    |

### My favorite word abcdef in
#### ASCII: 01100001 01100010 01100011 01100100 01100101 01100110
#### Huffman: 1100 1101 100 101 111 0


[Additional Sources](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/Huffman.html)