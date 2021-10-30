//716. Max Stack

class MaxStack
{
private:
	list<int> stac;
	map<int, vector<list<int>::interator>> sequence;

public:
	MaxStacl()
	{
	}
	void push(int x)
	{
		stac.push_front(x);
		sequence[x].push_back(stac.begin());
	}

	int pop(){
		int ret = stac.front();
		auto& pos = sequence[ret];
		pos.pop_back();
		if (pos.empty())
		{
			sequence.erase(ret);
		}
		stac.pop_front();
		return ret;
	}

	int top()
	{
		return stac.front();
	}
	int peekMax()
	{
		return sequence
	}
