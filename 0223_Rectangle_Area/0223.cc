class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    const int cx1 = ax1 < bx1 ? bx1 : ax1, cx2 = ax2 < bx2 ? ax2 : bx2, cy1 = ay1 < by1 ? by1 : ay1, cy2 = ay2 < by2 ? ay2 : by2;
    return (ax2 - ax1) * (ay2 - ay1) - (cx1 < cx2 && cy1 < cy2 ? (cx2 - cx1) * (cy2 - cy1) : 0) + (bx2 - bx1) * (by2 - by1);
  }
};