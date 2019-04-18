class CarPark
{
	private:
		int enteranceHour; int enteranceMin;
		int exitHour; int exitMin;
	 
	public:
		  float _suvPrice = 8;
		  float _truckPrice = 12;
		  float _sedanPrice = 6; 
		  float _normalCarPrice = 5; 

		float CalculatePrice(int entH,int entM, int exH, int exM, int vType);
		void Restart();
		void Initiate();
};
