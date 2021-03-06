/* Define a subplot class
** A drawing space where plots are made
** from corresponding PlotData class.
** A Plot window can have multiple Subplots
** and a Subplot can have multiple datasets
*/

#ifndef SUBPLOT_HPP
#define SUBPLOT_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <plotdata.hpp>

namespace cpl
{
    class Subplot
    {
        public:
            /* Plot view specific params */
            double x_min, x_max, y_min, y_max, x_range_scale, y_range_scale;
            double view_fraction, x_view_start, x_view_end, y_view_start, y_view_end;
            double subplot_padding;
            bool is_log_x, is_log_y;
            // bool custom_xrange
            std::string subplot_title;

            Subplot(double view_frctn);
            void initialize_plots();
            
            template<typename T, typename U>
            void addPlotdata(std::vector<T>& x, std::vector<U>& y, std::string format_string, std::string legend);
            
            void removePlotdata(unsigned int position);
            void draw(sf::RenderTarget* parent_wndw);

        private:
            sf::RenderTarget* parent_window;
            sf::Color gray;
            std::vector<cpl::PlotData> plot_datasets;
            unsigned int current_dataset;
            bool has_data;
            std::vector<sf::Color> common_colors;
            double mapValue(double min, double max, double value, double length, bool is_log10);
    };
}

#include <subplot.tpp>
#endif