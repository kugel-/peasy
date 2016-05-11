
namespace Peasy
{

public class Project : Object
{
    public string name { get { return _project.name; } private set {} }
    public string description { get { return _project.description; } private set {} }
    public string base_path { get { return _project.base_path; } private set {} }
    public string file_name { get { return _project.file_name; } private set {} }
    public string[] file_patterns { get { return _project.file_patterns; } private set {} }
    public int    pure { get; set; }

    internal Project.from_geany(Geany.Project project)
    {
        _project = project;
    }

    internal unowned Geany.Project? _project;

}

}
