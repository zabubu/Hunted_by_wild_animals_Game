#ifndef TIGRE_H
#define TIGRE_H

class tigre : public fauves
{
	public :
	tigre();
	tigre(const position &p);
	tigre(int x,int y);
	void deplaceVers(const joueur &j) override;
	position position();
	private :
	position d_pos;
}


#endif // TIGRE_H
