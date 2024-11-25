using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common.Models
{
    public class Movie : MongoDocument
    {
        public string Title { get; set; } = string.Empty;
        public List<string>? Actors { get; set; }
        public decimal? Budget { get; set; }
        public string Description { get; set; } = string.Empty;
    }
}
