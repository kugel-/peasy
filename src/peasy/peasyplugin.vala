
namespace Peasy
{

class Plugin : Peasy.Object
{
	protected unowned Geany.Plugin plugin;

	public Plugin(Geany.Plugin p)
	{
		this.plugin = p;
	}
}

}
