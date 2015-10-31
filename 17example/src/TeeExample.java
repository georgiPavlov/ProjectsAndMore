class TreeExample {
    public static void main(String[] args) {
        // Create the tree from the sample
        Tree<Integer> tree =
                new Tree<Integer>(7,
                        new Tree<Integer>(19,
                                new Tree<Integer>(1),
                                new Tree<Integer>(12),
                                new Tree<Integer>(31)),
                        new Tree<Integer>(21),
                        new Tree<Integer>(14,
                                new Tree<Integer>(23),
                                new Tree<Integer>(6))
                );

        // Traverse and print the tree using Depth-First-Search
        tree.printDFS();

        // Console output:
        // 7
        //    19
        //     1
        //     12
        //     31
        //    21
        //    14
        //     23
        //     6
    }
}

