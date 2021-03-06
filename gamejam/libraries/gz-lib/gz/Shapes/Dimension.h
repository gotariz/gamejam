#ifndef DIMENSION_H_INCLUDED
#define DIMENSION_H_INCLUDED

namespace gz
{

////////////////////////////////////////////////////////////
/// \brief A location in 2D space
////////////////////////////////////////////////////////////
template <class T>
class Dimension
{
    public:
        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        /// width of the dimension
        T w;
        /// height of the dimension
        T h;

        ////////////////////////////////////////////////////////////
        /// \brief defualt constructor - Data is initialised to zero.
        ////////////////////////////////////////////////////////////
        Dimension() :
        w(0),
        h(0)
        {}

        ////////////////////////////////////////////////////////////
        /// \brief auto initialising constructor
        ///
        ///\param w     width of the dimension
        ///\param h     height of the dimension
        ////////////////////////////////////////////////////////////
        Dimension(T width, T height) :
        w(width),
        h(height)
        {}

        ////////////////////////////////////////////////////////////
        /// \brief defualt destructor
        ////////////////////////////////////////////////////////////
        virtual ~Dimension(){}

        ////////////////////////////////////////////////////////////
        /// \brief sets the width and height dimensions
        ///
        ///\param w     w location of the point
        ///\param h     h location of the point
        ////////////////////////////////////////////////////////////
        void set(T width, T height)
        {
            w = width;
            h = height;
        }
};

}

#endif // DIMENSION_H_INCLUDED
