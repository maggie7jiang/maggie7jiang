//interative
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int unitCount = 0;
        int remainingTruckSize = truckSize;
        while (remainingTruckSize >0)
        {
            int maxUnitBoxIndex = findMaxUnitBox(boxTypes);
            if (maxUnitBoxIndex == -1)
            {
                break;
            }
            int boxCount = min(remainingTruckSize, boxTypes[maxUnitBoxIndex][0]);
            unitCount += boxCount * boxTypes[maxUnitBoxIndex][1];
            remainingTruckSize -= boxCount;
            boxTypes[maxUnitBoxIndex][1] = -1;
            
        }
        return unitCount;
    }
    int findMaxUnitBox(vector<vector<int>>& boxTypes)
    {
        int maxUnitBoxIndex = -1;
        int maxUnits = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (boxTypes[i][1] > maxUnits)
            {
                maxUnits = boxTypes[i][1];
                maxUnitBoxIndex = i;
            }
        }
        return maxUnitBoxIndex;
    }
};

//using Array sort
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), Comparator()); 
        
        int unitCount = 0;
        /*auto: auto keyword declares a variable whose type is deduced 
        from the initialization expression in its declaration. 
        The /Zc:auto[-] compiler option controls the meaning of the auto keyword.*/
        for (auto boxType : boxTypes) {
            int boxCount = min(truckSize, boxType[0]);
            unitCount += boxCount * boxType[1];
            truckSize -= boxCount;
            if (truckSize == 0) break;
        }
        return unitCount;
    }

    struct Comparator {
        bool operator()(vector<int> const& p1, vector<int> const& p2) {
            return p1[1] > p2[1];
        }
    };
};
//Time complexity: O(nlogn)
//space complexity: O(1)
