class Node:
    def __init__(self, char, frequency):
        self.char = char
        self.freq = frequency
        self.left = None
        self.right = None

    # Define comparison method for sorting
    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(sorted_freq_list):
    # Create a list of Node objects
    nodes = [Node(char, freq) for char, freq in sorted_freq_list]
    
    while len(nodes) > 1:
        # Find the two nodes with the lowest frequency
        left_index = min(range(len(nodes)), key=lambda i: nodes[i].freq)
        left = nodes[left_index]
        nodes[left_index] = None  # Mark as removed
        
        right_index = min(range(len(nodes)), key=lambda i: (nodes[i].freq if nodes[i] is not None else float('inf')))
        right = nodes[right_index]
        nodes[right_index] = None  # Mark as removed

        # Create a new internal node with these two nodes as children
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        nodes.append(merged)

        # Filter out None values (removed nodes)
        nodes = [node for node in nodes if node is not None]

    # Handle the last two nodes
    if len(nodes) == 2:
        left = nodes[0]
        right = nodes[1]
        if left.char is not None and right.char is None:
            return left  # Only left node needs to be returned
        elif left.char is None and right.char is not None:
            return right  # Only right node needs to be returned
        else:
            # Merge if both are leaf nodes
            merged = Node(None, left.freq + right.freq)
            merged.left = left
            merged.right = right
            return merged

    return nodes[0]  # The remaining node is the root of the Huffman Tree 

def generate_codes(node, current_code="", codes={}):
    if node is None:
        return
    
    # If this is a leaf node, assign the current code
    if node.char is not None:
        codes[node.char] = current_code

    # Traverse left and right children
    generate_codes(node.left, current_code + "0", codes)
    generate_codes(node.right, current_code + "1", codes)

    return codes
