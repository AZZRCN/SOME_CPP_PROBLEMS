template<typename t,bool safe = true>
class lsh{
	private:bool is_adding_data = true;
	public:
	unordered_map<t,size_t> con;
	unordered_map<size_t,t> uncon;
	vector<t> dat;
	vector<t> inner_vector;//for dbgs?
	size_t __size;
	void operator+(const t& x){
		assert(is_adding_data);
		dat.push_back(x);
	}
	void operator*(void){
		is_adding_data = false;
		sort(dat.begin(),dat.end(),less<t>());
		dat.erase(unique(dat.begin(),dat.end()),dat.end());
		__size = dat.size();
		for(size_t i = 0; i < __size; i++){
			con.insert(make_pair(dat[i],i));
			uncon.insert(make_pair(i,dat[i]));
		}
		inner_vector.resize(__size,0);
	}
	size_t operator()(const t& x){
		if constexpr(safe){
			assert(!is_adding_data);
			assert(con.find(x)!=con.end());	
		}
		return con.find(x)->second;
	}
	t operator[](const size_t& x){
		if constexpr(safe){
			assert(!is_adding_data);
			assert(uncon.find(x)!=uncon.end());	
		}
		return uncon.find(x)->second;
	}
	vector<t> get_keys(void){
		if constexpr(safe){
			assert(!is_adding_data);	
		}
		return dat;
	}
	size_t size(void){
		return __size;
	}
	t& p(const size_t& x){
		if constexpr(safe){
			assert(x<__size);
		}
		return inner_vector[x];
	}
};