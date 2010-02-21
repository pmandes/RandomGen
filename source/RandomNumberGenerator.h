#ifndef RANDOMNUMBERGENERATOR_H_
#define RANDOMNUMBERGENERATOR_H_

class RandomNumberGenerator {
	
	private:
		
		double a,b,c;
	
	public:
		RandomNumberGenerator(int,int,int);
		virtual ~RandomNumberGenerator();
		double uniformDistribution();
		double normalDistribution();
		double cauchyDistribution();
};

#endif /*RANDOMNUMBERGENERATOR_H_*/
