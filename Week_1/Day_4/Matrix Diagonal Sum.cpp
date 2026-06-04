class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int primary=0;
        int secondary=0;
        for (int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(i==j){
                    primary=primary +mat[i][j];
                }
                if((i+j)==mat.size()-1 && i!=j){
                    secondary=secondary+mat[i][j];
                }
            }
        }
        return primary +secondary;
    }
};