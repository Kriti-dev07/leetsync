class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);

        int overlapping_width=min(ax2,bx2)-max(ax1,bx1);
int overlapping_height=min(ay2,by2)-max(ay1,by1);

int overlapping_area=max(0,overlapping_width)*max(0,overlapping_height);
return area1+area2-overlapping_area;
    }
};