/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {
    Node build(int[][] G, int x0, int y0, int x1, int y1) {
        boolean flag = true;
        int t = G[x0][y0];
        for (int i = x0; i <= x1 && flag; i++) {
            for (int j = y0; j <= y1 && flag; j++) {
                if (G[i][j] != t) {
                    flag = false;
                }
            }
        }
        if (flag) {
            return new Node(G[x0][y0] > 0 ? true : false, true);
        } else {
            int xm = x0 + (x1 - x0) / 2, ym = y0 + (y1 - y0) / 2;
            Node tl = build(G, x0, y0, xm, ym);
            Node tr = build(G, x0, ym + 1, xm, y1);
            Node bl = build(G, xm + 1, y0, x1, ym);
            Node br = build(G, xm + 1, ym + 1, x1, y1);
            return new Node(G[x0][y0] > 0 ? true : false, false, tl, tr, bl, br);
        }
    }
    public Node construct(int[][] grid) {
        return build(grid, 0, 0, grid.length - 1, grid[0].length - 1);
    }
}