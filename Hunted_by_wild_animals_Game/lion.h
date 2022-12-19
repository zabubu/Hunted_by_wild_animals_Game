#ifndef LION_H
#define LION_H

class lion : public fauves
{
	public :
	lion();
	lion(const position &p);
	lion(int x,int y);
	void deplaceVers(const joueur &j) override;
	position position();
	private :
	position d_pos;
}


#endif // LION_H

