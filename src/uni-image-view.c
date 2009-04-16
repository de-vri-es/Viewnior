/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; coding: utf-8 -*- 
 *
 * Copyright © 2007-2009 Björn Lindqvist <bjourne@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

/**
 * SECTION:gtkimageview
 * @see_also: #UniAnimView
 * @short_description: General purpose image viewer for Gtk+
 * <mediaobject>
 *   <imageobject align = "center">
 *     <imagedata fileref = "gtkimageview-in-window.png" align = "center"/>
 *   </imageobject>
 *   <caption>
 *     <emphasis>Screenshot of the <filename>./tests/interactive</filename> demo
 *     application</emphasis>
 *   </caption>  
 * </mediaobject>
 *
 * <para>
 *   UniImageView is a full-featured general purpose image viewer
 *   widget for GTK. It provides a scrollable, zoomable pane in which
 *   a pixbuf can be displayed.
 * </para>
 * <refsect2>
 *   <title>Keybindings</title>
 *   <para>
 *     When focused, UniImageView responds to the following keybindings:
 *     <table width = "100%" border = "0">
 *       <thead>
 *         <tr>
 *           <th>Keys</th>
 *           <th>Corresponding function</th>
 *           <th>Description</th>
 *         </tr>  
 *       </thead>  
 *       <tbody>
 *         <tr>
 *           <td>%GDK_KP_Add, %GDK_equal, %GDK_plus</td>
 *           <td>uni_image_view_zoom_in()</td>
 *           <td>Causes the widget to zoom in one step.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_KP_Subtract, %GDK_minus</td>
 *           <td>uni_image_view_zoom_out()</td>
 *           <td>Causes the widget to zoom out one step.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_1</td>
 *           <td>uni_image_view_set_zoom()</td>
 *           <td>Sets zoom to 100%.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_2</td>
 *           <td>uni_image_view_set_zoom()</td>
 *           <td>Sets zoom to 200%.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_3</td>
 *           <td>uni_image_view_set_zoom()</td>
 *           <td>Sets zoom to 300%.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_x</td>
 *           <td>uni_image_view_set_fitting()</td>
 *           <td>Sets fitting to %TRUE so that the whole pixbuf
 *           becomes visible.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_Page_Up, %GDK_Up + %GDK_SHIFT_MASK</td>
 *           <td></td>
 *           <td>Scroll the view half a page upwards.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_Page_Down, %GDK_Down + %GDK_SHIFT_MASK</td>
 *           <td></td>
 *           <td>Scroll the view half a page downwards.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_Left + %GDK_SHIFT_MASK</td>
 *           <td></td>
 *           <td>Scroll the view half a page leftwards.</td>
 *         </tr>
 *         <tr>
 *           <td>%GDK_Right + %GDK_SHIFT_MASK</td>
 *           <td></td>
 *           <td>Scroll the view half a page rightwards.</td>
 *         </tr>  
 *       </tbody>          
 *     </table> 
 *   </para>
 * </refsect2>
 * <refsect2>
 *   <title>Mouse actions</title>
 *   <para>
 *     When focused, UniImageView responds to the following mouse
 *     actions:
 *   </para>
 *   <table width = "100%" border = "0">
 *       <thead>
 *         <tr>
 *           <th>Mouse gesture</th>
 *           <th>Description</th>
 *         </tr>  
 *       </thead>  
 *       <tbody>
 *         <tr>
 *           <td>Mouse wheel scroll + %GDK_CONTROL_MASK</td>
 *           <td>Increase or decrease the zoom of the view depending on
 *           the direction of the scroll.</td>
 *         </tr>  
 *       </tbody>
 *   </table>
 * </refsect2>
 * <refsect2>
 *   <title>Coordinate systems</title>
 *   <para>
 *     Operations on UniImageView are executed in three different
 *     2D coordinate systems:
 *   </para>
 *   <itemizedlist>
 *     <listitem>
 *       Image coordinates: each coordinate represents a pixel in the
 *       image. The range of valid coordinates goes
 *       from <emphasis>(0,0)-(p.w,p.h)</emphasis>,
 *       where <emphasis>p.w</emphasis> and <emphasis>p.h</emphasis>
 *       is the width and height of the image.
 *     </listitem>
 *     <listitem>
 *       Widget coordinates: each coordinate represents a pixel in the
 *       image view widgets coordinate system. The range of valid
 *       coordinates goes from <emphasis>(0,0)-(a.w,a.h)</emphasis>
 *       where <emphasis>a.w</emphasis> and <emphasis>a.h</emphasis> is
 *       the allocated width and height of the widget. Naturally, these
 *       coordinates are only valid for as long as the widget is
 *       realized.
 *     </listitem>
 *     <listitem>
 *       Zoom coordinates: this coordinate system is the most frequently
 *       used coordinate system in UniImageView. The range of valid
 *       coordinates goes from <emphasis>(0,0)-z(p.w,p.h)</emphasis>
 *       where <emphasis>p.w</emphasis> and <emphasis>p.h</emphasis> is
 *       the width and height of the image and <emphasis>z</emphasis> is
 *       the current zoom of the view. In other words, this coordinate
 *       system is simply the image coordinate system scaled.
 *     </listitem>
 *   </itemizedlist>
 * </refsect2>
 * <refsect2>
 *   <title>Settings</title>
 *   <para>
 *     UniImageView has a few settings that can be configured by users of
 *     the library. For example, when showing transparent images it may
 *     in certain cases be better to draw alpha transparent parts using
 *     the widgets background color instead of the default checkerboard:
 *     <informalexample>
 *       <programlisting>
 *         uni_image_view_set_transp (UNI_IMAGE_VIEW (view),
 *                                    GTK_IMAGE_TRANSP_COLOR,
 *                                    0x00000000);
 *       </programlisting>  
 *     </informalexample>
 *     When the window that is showing the widget is fullscreened, other
 *     settings has to be tweaked to make the view look as good as
 *     possible:
 *     <informalexample>
 *       <programlisting>
 *         uni_image_view_set_show_cursor (UNI_IMAGE_VIEW (view), FALSE);
 *       </programlisting>  
 *     </informalexample>
 *     Naturally, you should reset these settings again when the view
 *     leaves fullscreen mode.
 *   </para>
 *   <title>Updating the image data</title>
 *   <para>
 *     UniImageView aggresively caches the scaled image data. This
 *     behaviour is most often beneficial and makes the widget very
 *     fast. For example, try opening a very large image (4000x2000
 *     pixels or so) in UniImageView. The widget will spend some time
 *     bilinearly scaling the image at the start. Then try minimizing
 *     and unminimizing the window. The image will reappear immedately
 *     because the view has cached it.
 *   </para>
 *   <informalexample>
 *     <programlisting>
 *       // Do some operation on the pixbuf data here
 *       gtk_widget_queue_draw_area (10, 10, 50, 50) // Incorrect!
 *     </programlisting>
 *   </informalexample>
 * </refsect2>
 * <refsect1>
 *   <title>Example</title>
 *   <para>
 *     This is the minimal code needed for using UniImageView. 
 *   </para>
 *   <informalexample>
 *     <programlisting>
 * #include &lt;gtkimageview/gtkimageview.h&gt;
 * int
 * main (int argc, char *argv[])
 * {
 *     gtk_init (&amp;argc, &amp;argv);
 *     GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 *     GtkWidget *view = uni_image_view_new (<!-- -->);
 *     GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file ("tests/gnome_logo.jpg", NULL);
 * 
 *     uni_image_view_set_pixbuf (UNI_IMAGE_VIEW (view), pixbuf, TRUE);
 *     gtk_container_add (GTK_CONTAINER (window), view);
 *     gtk_widget_show_all (window);
 *     gtk_main ();
 * }
 *     </programlisting>  
 *   </informalexample>
 *   <para>
 *     Compile and run with:
 *   </para>
 *   <informalexample>
 *     <programlisting>
 * $ gcc -o minimal minimal.c `pkg-config --cflags --libs gtkimageview`
 * $ ./minimal
 *     </programlisting>
 *   </informalexample>
 *   <para>
 *     The result should look something like the following:
 *   </para>
 *   <mediaobject>
 *     <imageobject align = "center">
 *       <imagedata fileref = "ex-mini.png" align = "center"/>
 *     </imageobject>
 *   </mediaobject>
 *   <para>
 *     Note that because the example doesn't use #UniScrollWin many
 *     nice features aren't available.
 *   </para>  
 * </refsect1>
 **/

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <math.h>
#include <stdlib.h>

#include "uni-image-view.h"
#include "uni-dragger.h"
#include "uni-anim-view.h"
#include "uni-marshal.h"
#include "uni-zoom.h"
#include "uni-utils.h"

#define g_signal_handlers_disconnect_by_data(instance, data) \
    g_signal_handlers_disconnect_matched ((instance), G_SIGNAL_MATCH_DATA, \
                                          0, 0, NULL, NULL, (data))
#define g_signal_handlers_block_by_data(instance, data) \
    g_signal_handlers_block_matched ((instance), G_SIGNAL_MATCH_DATA, \
                                     0, 0, NULL, NULL, (data))
#define g_signal_handlers_unblock_by_data(instance, data) \
    g_signal_handlers_unblock_matched ((instance), G_SIGNAL_MATCH_DATA, \
                                       0, 0, NULL, NULL, (data))

/*************************************************************/
/***** Private data ******************************************/
/*************************************************************/
enum {
    SET_ZOOM,
    ZOOM_IN,
    ZOOM_OUT,
    SET_FITTING,
    SCROLL,
    ZOOM_CHANGED,
    PIXBUF_CHANGED,
    LAST_SIGNAL
};

static guint uni_image_view_signals[LAST_SIGNAL] = { 0 };

G_DEFINE_TYPE (UniImageView, uni_image_view, GTK_TYPE_WIDGET);

/*************************************************************/
/***** Static stuff ******************************************/
/*************************************************************/

static Size
uni_image_view_get_pixbuf_size (UniImageView * view)
{
    Size s = { 0, 0 };
    if (!view->pixbuf)
        return s;

    s.width = gdk_pixbuf_get_width (view->pixbuf);
    s.height = gdk_pixbuf_get_height (view->pixbuf);
    return s;
}

static Size
uni_image_view_get_allocated_size (UniImageView * view)
{
    Size size;
    size.width = GTK_WIDGET (view)->allocation.width;
    size.height = GTK_WIDGET (view)->allocation.height;
    return size;
}

static Size
uni_image_view_get_zoomed_size (UniImageView * view)
{
    Size size = uni_image_view_get_pixbuf_size (view);
    size.width = (int) (size.width * view->zoom + 0.5);
    size.height = (int) (size.height * view->zoom + 0.5);
    return size;
}

static void
uni_image_view_clamp_offset (UniImageView * view, gdouble * x, gdouble * y)
{
    Size alloc = uni_image_view_get_allocated_size (view);
    Size zoomed = uni_image_view_get_zoomed_size (view);

    *x = MIN (*x, zoomed.width - alloc.width);
    *y = MIN (*y, zoomed.height - alloc.height);
    *x = MAX (*x, 0);
    *y = MAX (*y, 0);
}

/**
 * uni_image_view_update_cursor:
 *
 * Query the tool what cursor it wants the view to display and then
 * use that cursor.
 *
 * Consider for example if the pointer is over a hotspot in the image.
 * If an arrow key is pressed, then the hotspot is moved, but the
 * cursor is not so no motion event is fired. Therefore, this method
 * must be called BOTH when the mouse is moved and when the offset is
 * changed.
 **/
/*static void
uni_image_view_update_cursor (UniImageView *view)
{
    GtkWidget *widget = GTK_WIDGET (view);
    if (!GTK_WIDGET_REALIZED (widget))
        return;
    int x, y;
    gdk_window_get_pointer (widget->window, &x, &y, NULL);
    GdkCursor *cursor = view->void_cursor;
    if (view->show_cursor)
        cursor = gtk_iimage_tool_cursor_at_point (view->tool, x, y);
    gdk_window_set_cursor (widget->window, cursor);
}*/

static void
uni_image_view_update_adjustments (UniImageView * view)
{
    Size zoomed = uni_image_view_get_zoomed_size (view);
    Size alloc = uni_image_view_get_allocated_size (view);

    view->hadj->lower = 0.0;
    view->hadj->upper = zoomed.width;
    view->hadj->value = view->offset_x;
    view->hadj->step_increment = 20.0;
    view->hadj->page_increment = alloc.width / 2;
    view->hadj->page_size = alloc.width;

    view->vadj->lower = 0.0;
    view->vadj->upper = zoomed.height;
    view->vadj->value = view->offset_y;
    view->vadj->step_increment = 20.0;
    view->vadj->page_increment = alloc.height / 2;
    view->vadj->page_size = alloc.height;

    g_signal_handlers_block_by_data (G_OBJECT (view->hadj), view);
    g_signal_handlers_block_by_data (G_OBJECT (view->vadj), view);
    gtk_adjustment_changed (view->hadj);
    gtk_adjustment_changed (view->vadj);
    g_signal_handlers_unblock_by_data (G_OBJECT (view->hadj), view);
    g_signal_handlers_unblock_by_data (G_OBJECT (view->vadj), view);
}

/**
 * This method must only be used by uni_image_view_zoom_to_fit () and
 * uni_image_view_set_zoom ().
 **/
static void
uni_image_view_set_zoom_with_center (UniImageView * view,
                                     gdouble zoom,
                                     gdouble center_x,
                                     gdouble center_y, gboolean is_allocating)
{
    gdouble zoom_ratio = zoom / view->zoom;

    gdouble offset_x, offset_y;
    offset_x = (view->offset_x + center_x) * zoom_ratio - center_x;
    offset_y = (view->offset_y + center_y) * zoom_ratio - center_y;
    view->zoom = zoom;

    uni_image_view_clamp_offset (view, &offset_x, &offset_y);
    view->offset_x = offset_x;
    view->offset_y = offset_y;
    //uni_image_view_update_cursor (view);

    if (!is_allocating && zoom_ratio != 1.0)
    {
        view->fitting = FALSE;
        uni_image_view_update_adjustments (view);
        gtk_widget_queue_draw (GTK_WIDGET (view));
    }
    if (zoom_ratio != 1.0)
    {
        /* zoom_ratio == 1.0 means zoom was not changed. */
        g_signal_emit (G_OBJECT (view),
                       uni_image_view_signals[ZOOM_CHANGED], 0);
    }
}

static void
uni_image_view_set_zoom_no_center (UniImageView * view,
                                   gdouble zoom, gboolean is_allocating)
{
    Size alloc = uni_image_view_get_allocated_size (view);
    gdouble center_x = alloc.width / 2.0;
    gdouble center_y = alloc.height / 2.0;
    uni_image_view_set_zoom_with_center (view, zoom,
                                         center_x, center_y, is_allocating);
}

static void
uni_image_view_zoom_to_fit (UniImageView * view, gboolean is_allocating)
{
    Size img = uni_image_view_get_pixbuf_size (view);
    Size alloc = uni_image_view_get_allocated_size (view);

    gdouble ratio_x = (gdouble) alloc.width / img.width;
    gdouble ratio_y = (gdouble) alloc.height / img.height;

    gdouble zoom = MIN (ratio_y, ratio_x);

    // Disallow to small zoom factors, they eat up all memory because
    // the filter matrices becomes to large. See #80925.
    zoom = CLAMP (zoom, UNI_ZOOM_MIN, 1.0);

    uni_image_view_set_zoom_no_center (view, zoom, is_allocating);
}

static void
uni_image_view_draw_background (UniImageView * view,
                                GdkRectangle * image_area, Size alloc)
{
    GtkWidget *widget = GTK_WIDGET (view);
    int n;

    GdkGC *gc = widget->style->bg_gc[GTK_STATE_NORMAL];

    GdkWindow *window = widget->window;

    GdkRectangle borders[4];
    GdkRectangle outer = { 0, 0, alloc.width, alloc.height };
    uni_rectangle_get_rects_around (&outer, image_area, borders);
    for (n = 0; n < 4; n++)
    {
        // Not sure why incrementing the size is necessary.
        borders[n].width++;
        borders[n].height++;
        uni_draw_rect (window, gc, TRUE, &borders[n]);
    }
}

/**
 * uni_image_view_repaint_area:
 * @paint_rect: The rectangle on the widget that needs to be redrawn.
 *
 * Redraws the porition of the widget defined by @paint_rect.
 **/
static int
uni_image_view_repaint_area (UniImageView * view, GdkRectangle * paint_rect)
{
    if (view->is_rendering)
        return FALSE;

    // Do not draw zero size rectangles.
    if (!paint_rect->width || !paint_rect->height)
        return FALSE;

    view->is_rendering = TRUE;

    // Image area is the area on the widget occupied by the pixbuf. 
    GdkRectangle image_area;
    Size alloc = uni_image_view_get_allocated_size (view);
    uni_image_view_get_draw_rect (view, &image_area);
    if (image_area.x > 0 ||
        image_area.y > 0 ||
        image_area.width < alloc.width || image_area.height < alloc.height)
    {
        uni_image_view_draw_background (view, &image_area, alloc);
    }
    GtkWidget *widget = GTK_WIDGET (view);

    // Paint area is the area on the widget that should be redrawn.
    GdkRectangle paint_area;
    gboolean intersects = gdk_rectangle_intersect (&image_area,
                                                   paint_rect,
                                                   &paint_area);
    if (intersects && view->pixbuf)
    {
        GdkInterpType interp;
        if (view->zoom <= 1.0)
        {
            interp = GDK_INTERP_TILES;
        }
        else
        {
            interp = view->interp;
        }
        int src_x =
            (int) ((view->offset_x + (gdouble) paint_area.x -
                    (gdouble) image_area.x) + 0.5);
        int src_y =
            (int) ((view->offset_y + (gdouble) paint_area.y -
                    (gdouble) image_area.y) + 0.5);

        UniPixbufDrawOpts opts = {
            view->zoom,
            (GdkRectangle) {src_x, src_y,
                            paint_area.width, paint_area.height},
            paint_area.x, paint_area.y,
            interp,
            view->pixbuf
        };
        uni_dragger_paint_image ((UniDragger *) view->tool, &opts,
                                 widget->window);
    }

    view->is_rendering = FALSE;
    return TRUE;
}

/**
 * uni_image_view_fast_scroll:
 *
 * Actually scroll the views window using gdk_draw_drawable().
 * GTK_WIDGET (view)->window is guaranteed to be non-NULL in this
 * function.
 **/
static void
uni_image_view_fast_scroll (UniImageView * view, int delta_x, int delta_y)
{
    GdkDrawable *drawable = GTK_WIDGET (view)->window;

    int src_x, src_y;
    int dest_x, dest_y;
    if (delta_x < 0)
    {
        src_x = 0;
        dest_x = -delta_x;
    }
    else
    {
        src_x = delta_x;
        dest_x = 0;
    }
    if (delta_y < 0)
    {
        src_y = 0;
        dest_y = -delta_y;
    }
    else
    {
        src_y = delta_y;
        dest_y = 0;
    }

    /* First move the part of the image that did not become hidden or
       shown by this operation. gdk_draw_drawable is probably very
       fast because it does not involve sending any data to the X11
       server.

       Remember that X11 is weird shit. It does not remember how
       windows beneath other windows look like. So if another window
       overlaps this window, it will temporarily look corrupted. We
       fix that later by turning on "exposures." See below. */

    GdkGC *gc = gdk_gc_new (drawable);
    Size alloc = uni_image_view_get_allocated_size (view);

    gdk_gc_set_exposures (gc, TRUE);
    gdk_draw_drawable (drawable,
                       gc,
                       drawable,
                       src_x, src_y,
                       dest_x, dest_y,
                       alloc.width - abs (delta_x),
                       alloc.height - abs (delta_y));
    g_object_unref (gc);

    /* If we moved in both the x and y directions, two "strips" of the
       image becomes visible. One horizontal strip and one vertical
       strip. */
    GdkRectangle horiz_strip = {
        0,
        (delta_y < 0) ? 0 : alloc.height - abs (delta_y),
        alloc.width,
        abs (delta_y)
    };
    uni_image_view_repaint_area (view, &horiz_strip);

    GdkRectangle vert_strip = {
        (delta_x < 0) ? 0 : alloc.width - abs (delta_x),
        0,
        abs (delta_x),
        alloc.height
    };
    uni_image_view_repaint_area (view, &vert_strip);

    // Here is where we fix the weirdness mentioned above. I do not
    // really know why it works, but it does!
    GdkEvent *ev;
    while ((ev = gdk_event_get_graphics_expose (drawable)) != NULL)
    {
        GdkEventExpose *expose = (GdkEventExpose *) ev;
        int exp_count = expose->count;
        uni_image_view_repaint_area (view, &expose->area);
        gdk_event_free (ev);
        if (exp_count == 0)
            break;
    }
}

/**
 * uni_image_view_scroll_to:
 * @offset_x: X part of the offset in zoom space coordinates.
 * @offset_y: Y part of the offset in zoom space coordinates.
 * @set_adjustments: whether to update the adjustments. Because this
 *   function is called from the adjustments callbacks, it needs to be
 *   %FALSE to prevent infinite recursion.
 * @invalidate: whether to invalidate the view or redraw immedately,
 *  see uni_image_view_set_offset()
 *
 * Set the offset of where in the image the #UniImageView should begin
 * to display image data.
 **/
static void
uni_image_view_scroll_to (UniImageView * view,
                          gdouble offset_x,
                          gdouble offset_y,
                          gboolean set_adjustments, gboolean invalidate)
{
    int delta_x, delta_y;

    uni_image_view_clamp_offset (view, &offset_x, &offset_y);

    /* Round avoids floating point to integer conversion errors. See 
     */
    delta_x = floor (offset_x - view->offset_x + 0.5);
    delta_y = floor (offset_y - view->offset_y + 0.5);

    /* Exit early if the scroll was smaller than one (zoom space)
       pixel. */
    if (delta_x == 0 && delta_y == 0)
        return;

    view->offset_x = offset_x;
    view->offset_y = offset_y;
    //uni_image_view_update_cursor (view);

    if (GTK_WIDGET (view)->window)
    {
        if (invalidate)
            gdk_window_invalidate_rect (GTK_WIDGET (view)->window, NULL,
                                        TRUE);
        else
            uni_image_view_fast_scroll (view, delta_x, delta_y);
    }

    if (!set_adjustments)
        return;

    g_signal_handlers_block_by_data (G_OBJECT (view->hadj), view);
    g_signal_handlers_block_by_data (G_OBJECT (view->vadj), view);
    gtk_adjustment_set_value (view->hadj, view->offset_x);
    gtk_adjustment_set_value (view->vadj, view->offset_y);
    g_signal_handlers_unblock_by_data (G_OBJECT (view->hadj), view);
    g_signal_handlers_unblock_by_data (G_OBJECT (view->vadj), view);
}

static void
uni_image_view_scroll (UniImageView * view,
                       GtkScrollType xscroll, GtkScrollType yscroll)
{
    int xstep = 0;
    if (xscroll == GTK_SCROLL_STEP_LEFT)
        xstep = -view->hadj->step_increment;
    else if (xscroll == GTK_SCROLL_STEP_RIGHT)
        xstep = view->hadj->step_increment;
    else if (xscroll == GTK_SCROLL_PAGE_LEFT)
        xstep = -view->hadj->page_increment;
    else if (xscroll == GTK_SCROLL_PAGE_RIGHT)
        xstep = view->hadj->page_increment;

    int ystep = 0;
    if (yscroll == GTK_SCROLL_STEP_UP)
        ystep = -view->vadj->step_increment;
    else if (yscroll == GTK_SCROLL_STEP_DOWN)
        ystep = view->vadj->step_increment;
    else if (yscroll == GTK_SCROLL_PAGE_UP)
        ystep = -view->vadj->page_increment;
    else if (yscroll == GTK_SCROLL_PAGE_DOWN)
        ystep = view->vadj->page_increment;

    uni_image_view_scroll_to (view,
                              view->offset_x + xstep,
                              view->offset_y + ystep, TRUE, FALSE);
}

/*************************************************************/
/***** Private signal handlers *******************************/
/*************************************************************/
static void
uni_image_view_realize (GtkWidget * widget)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    GTK_WIDGET_SET_FLAGS (widget, GTK_REALIZED);

    GdkWindowAttr attrs;
    attrs.window_type = GDK_WINDOW_CHILD;
    attrs.x = widget->allocation.x;
    attrs.y = widget->allocation.y;
    attrs.width = widget->allocation.width;
    attrs.height = widget->allocation.height;
    attrs.wclass = GDK_INPUT_OUTPUT;
    attrs.visual = gtk_widget_get_visual (widget);
    attrs.colormap = gtk_widget_get_colormap (widget);
    attrs.event_mask = (gtk_widget_get_events (widget)
                        | GDK_EXPOSURE_MASK
                        | GDK_BUTTON_MOTION_MASK
                        | GDK_BUTTON_PRESS_MASK
                        | GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK);

    int attr_mask = (GDK_WA_X | GDK_WA_Y | GDK_WA_VISUAL | GDK_WA_COLORMAP);
    GdkWindow *parent = gtk_widget_get_parent_window (widget);
    widget->window = gdk_window_new (parent, &attrs, attr_mask);
    gdk_window_set_user_data (widget->window, view);

    widget->style = gtk_style_attach (widget->style, widget->window);
    gtk_style_set_background (widget->style, widget->window,
                              GTK_STATE_NORMAL);

    view->void_cursor = gdk_cursor_new (GDK_ARROW);

    //uni_image_view_update_cursor (view);
}

static void
uni_image_view_unrealize (GtkWidget * widget)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    gdk_cursor_unref (view->void_cursor);
    GTK_WIDGET_CLASS (uni_image_view_parent_class)->unrealize (widget);
}

static void
uni_image_view_size_allocate (GtkWidget * widget, GtkAllocation * alloc)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    widget->allocation = *alloc;

    if (view->pixbuf && view->fitting)
        uni_image_view_zoom_to_fit (view, TRUE);

    uni_image_view_clamp_offset (view, &view->offset_x, &view->offset_y);

    uni_image_view_update_adjustments (view);

    if (GTK_WIDGET_REALIZED (widget))
        gdk_window_move_resize (widget->window,
                                alloc->x, alloc->y,
                                alloc->width, alloc->height);
}

static void
uni_image_view_style_set (GtkWidget * widget, GtkStyle * prev)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    GTK_WIDGET_CLASS (uni_image_view_parent_class)->style_set (widget, prev);

    if (view->transp != GTK_IMAGE_TRANSP_BACKGROUND)
        return;
}

static int
uni_image_view_expose (GtkWidget * widget, GdkEventExpose * ev)
{
    return uni_image_view_repaint_area (UNI_IMAGE_VIEW (widget), &ev->area);
}

static int
uni_image_view_button_press (GtkWidget * widget, GdkEventButton * ev)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    if (ev->type == GDK_BUTTON_PRESS && ev->button == 1)
    {
        return uni_dragger_button_press ((UniDragger *) view->tool, ev);
    }
    else if (ev->type == GDK_2BUTTON_PRESS && ev->button == 1)
    {
        if (uni_image_view_get_fitting (view))
        {
            uni_image_view_set_zoom_with_center (view, 1., ev->x, ev->y,
                                                 FALSE);
        }
        else
        {
            uni_image_view_set_fitting (view, TRUE);
        }
        return 1;
    }
    return 0;
}

static int
uni_image_view_button_release (GtkWidget * widget, GdkEventButton * ev)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    return uni_dragger_button_release ((UniDragger *) view->tool, ev);
}

static int
uni_image_view_motion_notify (GtkWidget * widget, GdkEventMotion * ev)
{
    UniImageView *view = UNI_IMAGE_VIEW (widget);
    if (view->is_rendering)
        return FALSE;
    //uni_image_view_update_cursor (view);
    return uni_dragger_motion_notify ((UniDragger *) view->tool, ev);
}

static gboolean
uni_image_view_hadj_changed_cb (GtkObject * adj, UniImageView * view)
{
    int offset_x;
    offset_x = GTK_ADJUSTMENT (adj)->value;
    uni_image_view_scroll_to (view, offset_x, view->offset_y, FALSE, FALSE);
    return FALSE;
}

static gboolean
uni_image_view_vadj_changed_cb (GtkObject * adj, UniImageView * view)
{
    int offset_y;
    offset_y = GTK_ADJUSTMENT (adj)->value;
    uni_image_view_scroll_to (view, view->offset_x, offset_y, FALSE, FALSE);
    return FALSE;
}

static int
uni_image_view_scroll_event (GtkWidget * widget, GdkEventScroll * ev)
{
    gdouble zoom;
    UniImageView *view = UNI_IMAGE_VIEW (widget);

    // Horizontal scroll left is equivalent to scroll up and right is
    // like scroll down. No idea if that is correct -- I have no input
    // device that can do horizontal scrolls.
    if (ev->direction == GDK_SCROLL_UP || ev->direction == GDK_SCROLL_LEFT)
    {
        zoom = CLAMP (view->zoom * UNI_ZOOM_STEP, UNI_ZOOM_MIN, UNI_ZOOM_MAX);
    }
    else
    {
        zoom = CLAMP (view->zoom / UNI_ZOOM_STEP, UNI_ZOOM_MIN, UNI_ZOOM_MAX);
    }
    uni_image_view_set_zoom_with_center (view, zoom, ev->x, ev->y, FALSE);

    return TRUE;
}

static void
uni_image_view_set_scroll_adjustments (UniImageView * view,
                                       GtkAdjustment * hadj,
                                       GtkAdjustment * vadj)
{
    if (hadj && view->hadj && view->hadj != hadj)
    {
        g_signal_handlers_disconnect_by_data (G_OBJECT (view->hadj), view);
        g_object_unref (view->hadj);
        g_signal_connect (G_OBJECT (hadj),
                          "value_changed",
                          G_CALLBACK (uni_image_view_hadj_changed_cb), view);
        view->hadj = hadj;
        g_object_ref (view->hadj);
        gtk_object_sink (GTK_OBJECT (view->hadj));
    }
    if (vadj && view->vadj && view->vadj != vadj)
    {
        g_signal_handlers_disconnect_by_data (G_OBJECT (view->vadj), view);
        g_object_unref (view->vadj);
        g_signal_connect (G_OBJECT (vadj),
                          "value_changed",
                          G_CALLBACK (uni_image_view_vadj_changed_cb), view);
        view->vadj = vadj;
        g_object_ref (view->vadj);
        gtk_object_sink (GTK_OBJECT (view->vadj));
    }
}


/*************************************************************/
/***** Stuff that deals with the type ************************/
/*************************************************************/
static void
uni_image_view_init (UniImageView * view)
{
    GTK_WIDGET_SET_FLAGS (view, GTK_CAN_FOCUS);

    view->interp = GDK_INTERP_BILINEAR;
    view->fitting = TRUE;
    view->pixbuf = NULL;
    view->zoom = 1.0;
    view->offset_x = 0.0;
    view->offset_y = 0.0;
    view->is_rendering = FALSE;
    view->show_cursor = TRUE;
    view->void_cursor = NULL;
    view->tool = (GObject *) uni_dragger_new ((GtkWidget *) view);

    view->transp = GTK_IMAGE_TRANSP_GRID;

    view->hadj = GTK_ADJUSTMENT (gtk_adjustment_new (0.0, 1.0, 0.0,
                                                     1.0, 1.0, 1.0));
    view->vadj = GTK_ADJUSTMENT (gtk_adjustment_new (0.0, 1.0, 0.0,
                                                     1.0, 1.0, 1.0));
    g_object_ref (view->hadj);
    gtk_object_sink (GTK_OBJECT (view->hadj));
    g_object_ref (view->vadj);
    gtk_object_sink (GTK_OBJECT (view->vadj));

    GtkWidget *widget = (GtkWidget *) view;
    widget->allocation.width = 0;
    widget->allocation.height = 0;
}

static void
uni_image_view_finalize (GObject * object)
{
    UniImageView *view = UNI_IMAGE_VIEW (object);
    if (view->hadj)
    {
        g_signal_handlers_disconnect_by_data (G_OBJECT (view->hadj), view);
        g_object_unref (view->hadj);
        view->hadj = NULL;
    }
    if (view->vadj)
    {
        g_signal_handlers_disconnect_by_data (G_OBJECT (view->vadj), view);
        g_object_unref (view->vadj);
        view->vadj = NULL;
    }
    if (view->pixbuf)
    {
        g_object_unref (view->pixbuf);
        view->pixbuf = NULL;
    }
    g_object_unref (view->tool);
    /* Chain up. */
    G_OBJECT_CLASS (uni_image_view_parent_class)->finalize (object);
}

static void
uni_image_view_init_signals (UniImageViewClass * klass)
{
    /**
     * UniImageView::set-zoom:
     * @view: The #UniImageView that received the signal.
     * @zoom: The new zoom factor.
     *
     * The ::set-zoom signal is a keybinding signal emitted when
     * %GDK_1, %GDK_2 or %GDK_3 is pressed on the widget which causes
     * the zoom to be set to 100%, 200% or 300%. The signal should not
     * be used by clients of this library.
     **/
    uni_image_view_signals[SET_ZOOM] =
        g_signal_new ("set_zoom",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
                      G_STRUCT_OFFSET (UniImageViewClass, set_zoom),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__DOUBLE,
                      G_TYPE_NONE, 1, G_TYPE_DOUBLE);
    uni_image_view_signals[ZOOM_IN] =
        g_signal_new ("zoom_in",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
                      G_STRUCT_OFFSET (UniImageViewClass, zoom_in),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
    /**
     * UniImageView::zoom-out:
     * @view: The #UniImageView that received the signal.
     *
     * The ::zoom-out signal is a keybinding signal emitted when
     * %GDK_minus or %GDK_KP_Subtract is pressed on the widget. The
     * signal should not be used by clients of this library.
     **/
    uni_image_view_signals[ZOOM_OUT] =
        g_signal_new ("zoom_out",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
                      G_STRUCT_OFFSET (UniImageViewClass, zoom_out),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
    /**
     * UniImageView::set-fit-mode:
     * @view: the #UniImageView that received the signal.
     * @fiting: whether to fit the image or not
     *
     * The ::set-fit-mode signal is a keybinding signal emitted when
     * the %GDK_W key is pressed on the widget. The signal should not
     * be used by clients of this library.
     **/
    uni_image_view_signals[SET_FITTING] =
        g_signal_new ("set_fitting",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
                      G_STRUCT_OFFSET (UniImageViewClass, set_fitting),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__BOOLEAN,
                      G_TYPE_NONE, 1, G_TYPE_INT);
    /**
     * UniImageView::scroll:
     * @view: The #UniImageView that received the signal.
     * @xscroll: Horizontal scroll constant.
     * @yscroll: Vertical scroll constant.
     *
     * The ::scroll signal is a keybinding signal emitted when a key
     * is used to scroll the view. The signal should not be used by
     * clients of this library.
     **/
    uni_image_view_signals[SCROLL] =
        g_signal_new ("scroll",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
                      G_STRUCT_OFFSET (UniImageViewClass, scroll),
                      NULL, NULL,
                      uni_marshal_VOID__ENUM_ENUM,
                      G_TYPE_NONE,
                      2, GTK_TYPE_SCROLL_TYPE, GTK_TYPE_SCROLL_TYPE);
    /**
     * UniImageView::zoom-changed:
     * @view: The #UniImageView that emitted the signal.
     *
     * The ::zoom-changed signal is emitted when the zoom factor of
     * the view changes. Listening to this signal is useful if, for
     * example, you have a label that displays the zoom factor of the
     * view. Use uni_image_view_get_zoom() to retrieve the value. For
     * example:
     *
     * <informalexample>
     *   <programlisting>
     *     // Handler that will be called when the zoom changes.
     *     static void
     *     zoom_cb (UniImageView *view,
     *              GtkLabel     *label)
     *     {
     *         gdouble zoom = uni_image_view_get_zoom (view);
     *         char *text = g_strdup_printf ("%d%%", (int)(zoom * 100.0));
	 *         gtk_label_set_text (label, text);
     *         g_free (text);
     *     }
     *     ...
     *     // Connect the callback to the signal.
     *     GtkWidget *label = gtk_label_new ("100%");
     *     g_signal_connect (G_OBJECT (view), "zoom-changed",
     *                       G_CALLBACK (zoom_cb), label);
     *   </programlisting>
     * </informalexample>
     **/
    uni_image_view_signals[ZOOM_CHANGED] =
        g_signal_new ("zoom_changed",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST,
                      G_STRUCT_OFFSET (UniImageViewClass, zoom_changed),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
    /**
     * UniImageView::pixbuf-changed:
     * @view: The view that emitted the signal.
     *
     * The ::pixbuf-changed signal is emitted when the pixbuf the
     * image view shows is changed and when its image data is changed.
     * Listening to this signal is useful if you, for example, have a
     * label that displays the width and height of the pixbuf in the
     * view.
     *
     * <informalexample>
     *   <programlisting>
     *     // Handler that will be called when the pixbuf changes.
     *     static void
     *     pixbuf_cb (UniImageView *view,
     *                GtkLabel     *label)
     *     {
     *         GdkPixbuf *new_pb = uni_image_view_get_pixbuf (view);
     *         if (!new_pb)
     *         {
     *             // Empty label if no pixbuf.
     *             gtk_label_set_text (label, "");
     *             return;
     *         }
     *         int width = gdk_pixbuf_get_width (new_pb);
     *         int height = gdk_pixbuf_get_height (new_pb);
     *         char *text = g_strdup_printf ("%d, %d", width, height);
     *         gtk_label_set_text (label, text);
     *         g_free (text);
     *     }
     *     ...
     *     GtkWidget *label = gtk_label_new ("");
     *     g_signal_connect (G_OBJECT (view), "pixbuf-changed",
     *                       G_CALLBACK (pixbuf_cb), label);
     *   </programlisting>
     * </informalexample>
     **/
    uni_image_view_signals[PIXBUF_CHANGED] =
        g_signal_new ("pixbuf_changed",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST,
                      G_STRUCT_OFFSET (UniImageViewClass, pixbuf_changed),
                      NULL, NULL,
                      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void
uni_image_view_class_init (UniImageViewClass * klass)
{
    uni_image_view_init_signals (klass);

    GObjectClass *object_class = (GObjectClass *) klass;
    object_class->finalize = uni_image_view_finalize;

    GtkWidgetClass *widget_class = (GtkWidgetClass *) klass;
    widget_class->button_press_event = uni_image_view_button_press;
    widget_class->button_release_event = uni_image_view_button_release;
    widget_class->expose_event = uni_image_view_expose;
    widget_class->motion_notify_event = uni_image_view_motion_notify;
    widget_class->realize = uni_image_view_realize;
    widget_class->scroll_event = uni_image_view_scroll_event;
    widget_class->size_allocate = uni_image_view_size_allocate;
    widget_class->style_set = uni_image_view_style_set;
    widget_class->unrealize = uni_image_view_unrealize;

    klass->set_zoom = uni_image_view_set_zoom;
    klass->zoom_in = uni_image_view_zoom_in;
    klass->zoom_out = uni_image_view_zoom_out;
    klass->set_fitting = uni_image_view_set_fitting;
    klass->scroll = uni_image_view_scroll;
    klass->zoom_changed = NULL;
    klass->pixbuf_changed = NULL;

    /**
     * UniImageView::set-scroll-adjustments
     *
     * Do we really need this signal? It should be intrinsic to the
     * GtkWidget class, shouldn't it?
     **/
    widget_class->set_scroll_adjustments_signal =
        g_signal_new ("set_scroll_adjustments",
                      G_TYPE_FROM_CLASS (klass),
                      G_SIGNAL_RUN_LAST,
                      G_STRUCT_OFFSET (UniImageViewClass,
                                       set_scroll_adjustments),
                      NULL, NULL,
                      uni_marshal_VOID__POINTER_POINTER,
                      G_TYPE_NONE,
                      2, GTK_TYPE_ADJUSTMENT, GTK_TYPE_ADJUSTMENT);
    klass->set_scroll_adjustments = uni_image_view_set_scroll_adjustments;

    /* Add keybindings. */
    GtkBindingSet *binding_set = gtk_binding_set_by_class (klass);

    /* Set zoom. */
    gtk_binding_entry_add_signal (binding_set, GDK_1, 0,
                                  "set_zoom", 1, G_TYPE_DOUBLE, 1.0);
    gtk_binding_entry_add_signal (binding_set, GDK_2, 0,
                                  "set_zoom", 1, G_TYPE_DOUBLE, 2.0);
    gtk_binding_entry_add_signal (binding_set, GDK_3, 0,
                                  "set_zoom", 1, G_TYPE_DOUBLE, 3.0);

    /* Zoom in */
    gtk_binding_entry_add_signal (binding_set, GDK_plus, 0, "zoom_in", 0);
    gtk_binding_entry_add_signal (binding_set, GDK_equal, 0, "zoom_in", 0);
    gtk_binding_entry_add_signal (binding_set, GDK_KP_Add, 0, "zoom_in", 0);

    /* Zoom out */
    gtk_binding_entry_add_signal (binding_set, GDK_minus, 0, "zoom_out", 0);
    gtk_binding_entry_add_signal (binding_set, GDK_KP_Subtract, 0,
                                  "zoom_out", 0);

    /* Set fitting */
    gtk_binding_entry_add_signal (binding_set, GDK_x, 0,
                                  "set_fitting", 1, G_TYPE_BOOLEAN, TRUE);

    /* Unmodified scrolling */
    gtk_binding_entry_add_signal (binding_set, GDK_Right, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_STEP_RIGHT,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_NONE);
    gtk_binding_entry_add_signal (binding_set, GDK_Left, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_STEP_LEFT,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_NONE);
    gtk_binding_entry_add_signal (binding_set, GDK_Down, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_STEP_DOWN);
    gtk_binding_entry_add_signal (binding_set, GDK_Up, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_STEP_UP);

    /* Shifted scrolling */
    gtk_binding_entry_add_signal (binding_set, GDK_Right, GDK_SHIFT_MASK,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_PAGE_RIGHT,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_NONE);
    gtk_binding_entry_add_signal (binding_set, GDK_Left, GDK_SHIFT_MASK,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_PAGE_LEFT,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_NONE);
    gtk_binding_entry_add_signal (binding_set, GDK_Up, GDK_SHIFT_MASK,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_PAGE_UP);
    gtk_binding_entry_add_signal (binding_set, GDK_Down, GDK_SHIFT_MASK,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_PAGE_DOWN);

    /* Page Up & Down */
    gtk_binding_entry_add_signal (binding_set, GDK_Page_Up, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_PAGE_UP);
    gtk_binding_entry_add_signal (binding_set, GDK_Page_Down, 0,
                                  "scroll", 2,
                                  GTK_TYPE_SCROLL_TYPE,
                                  GTK_SCROLL_NONE,
                                  GTK_TYPE_SCROLL_TYPE, GTK_SCROLL_PAGE_DOWN);
}

/**
 * uni_image_view_new:
 * @returns: a new #UniImageView.
 *
 * Creates a new image view with default values. The default values
 * are:
 *
 * <itemizedlist>
 *  <listitem>black bg : %FALSE</listitem>
 *  <listitem>fitting : %TRUE</listitem>
 *  <listitem>image tool : a #UniDragger instance</listitem>
 *  <listitem>interpolation mode : %GDK_INTERP_BILINEAR</listitem>
 *  <listitem>offset : (0, 0)</listitem>
 *  <listitem>pixbuf : %NULL</listitem>
 *  <listitem>show cursor: %TRUE</listitem>
 *  <listitem>show frame : %TRUE</listitem>
 *  <listitem>transp : #GTK_IMAGE_TRANSP_GRID</listitem>
 *  <listitem>zoom : 1.0</listitem>
 * </itemizedlist>
 **/
GtkWidget *
uni_image_view_new (void)
{
    GtkWidget *view = g_object_new (UNI_TYPE_IMAGE_VIEW, NULL);
    return view;
}

/*************************************************************/
/***** Read-only properties **********************************/
/*************************************************************/
/**
 * uni_image_view_get_viewport:
 * @view: a #UniImageView
 * @rect: a #GdkRectangle to fill in with the current viewport or
 *   %NULL.
 * @returns: %TRUE if a #GdkPixbuf is shown, %FALSE otherwise.
 *
 * Fills in the rectangle with the current viewport. If pixbuf is
 * %NULL, there is no viewport, @rect is left untouched and %FALSE is
 * returned.
 *
 * The current viewport is defined as the rectangle, in zoomspace
 * coordinates as the area of the loaded pixbuf the #UniImageView is
 * currently showing.
 **/
gboolean
uni_image_view_get_viewport (UniImageView * view, GdkRectangle * rect)
{
    gboolean ret_val = (view->pixbuf != NULL);
    if (!rect || !ret_val)
        return ret_val;

    Size alloc = uni_image_view_get_allocated_size (view);
    Size zoomed = uni_image_view_get_zoomed_size (view);
    rect->x = view->offset_x;
    rect->y = view->offset_y;
    rect->width = MIN (alloc.width, zoomed.width);
    rect->height = MIN (alloc.height, zoomed.height);
    return TRUE;
}

/**
 * uni_image_view_get_draw_rect:
 * @view: a #UniImageView
 * @rect: a #GdkRectangle to fill in with the area of the widget in
 *   which the pixbuf is drawn.
 * @returns: %TRUE if the view is allocated and has a pixbuf, %FALSE
 *   otherwise.
 *
 * Get the rectangle in the widget where the pixbuf is painted. 
 *
 * For example, if the widgets allocated size is 100, 100 and the
 * pixbufs size is 50, 50 and the zoom factor is 1.0, then the pixbuf
 * will be drawn centered on the widget. @rect will then be
 * (25,25)-[50,50].
 *
 * This method is useful when converting from widget to image or zoom
 * space coordinates.
 **/
gboolean
uni_image_view_get_draw_rect (UniImageView * view, GdkRectangle * rect)
{
    if (!view->pixbuf)
        return FALSE;
    Size alloc = uni_image_view_get_allocated_size (view);
    Size zoomed = uni_image_view_get_zoomed_size (view);

    rect->x = (alloc.width - zoomed.width) / 2;
    rect->y = (alloc.height - zoomed.height) / 2;
    rect->x = MAX (rect->x, 0);
    rect->y = MAX (rect->y, 0);
    rect->width = MIN (zoomed.width, alloc.width);
    rect->height = MIN (zoomed.height, alloc.height);
    return TRUE;
}

/*************************************************************/
/***** Write-only properties *********************************/
/*************************************************************/
/**
 * uni_image_view_set_offset:
 * @view: A #UniImageView.
 * @x: X-component of the offset in zoom space coordinates.
 * @y: Y-component of the offset in zoom space coordinates.
 * @invalidate: whether to invalidate the view or redraw immediately.
 *
 * Sets the offset of where in the image the #UniImageView should
 * begin displaying image data.
 *
 * The offset is clamped so that it will never cause the #UniImageView
 * to display pixels outside the pixbuf. Setting this attribute causes
 * the widget to repaint itself if it is realized.
 *
 * If @invalidate is %TRUE, the views entire area will be invalidated
 * instead of redrawn immediately. The view is then queued for redraw,
 * which means that additional operations can be performed on it
 * before it is redrawn.
 *
 * The difference can sometimes be important like when you are
 * overlaying data and get flicker or artifacts when setting the
 * offset. If that happens, setting @invalidate to %TRUE could fix the
 * problem. See the source code to #GtkImageToolSelector for an
 * example.
 *
 * Normally, @invalidate should always be %FALSE because it is much
 * faster to repaint immedately than invalidating.
 **/
void
uni_image_view_set_offset (UniImageView * view,
                           gdouble offset_x,
                           gdouble offset_y, gboolean invalidate)
{
    uni_image_view_scroll_to (view, offset_x, offset_y, TRUE, invalidate);
}

/*************************************************************/
/***** Read-write properties *********************************/
/*************************************************************/
/**
 * uni_image_view_get_fitting:
 * @view: a #UniImageView
 * @returns: %TRUE if the view is fitting the image, %FALSE otherwise.
 *
 * Returns the fitting setting of the view.
 **/
gboolean
uni_image_view_get_fitting (UniImageView * view)
{
    return view->fitting;
}

/**
 * uni_image_view_set_fitting:
 * @view: a #UniImageView.
 * @fitting: whether to fit the image or not
 *
 * Sets whether to fit or not. If %TRUE, then the view will adapt the
 * zoom so that the whole pixbuf is visible.
 *
 * Setting the fitting causes the widget to immediately repaint
 * itself.
 *
 * Fitting is by default %TRUE.
 **/
void
uni_image_view_set_fitting (UniImageView * view, gboolean fitting)
{
    g_return_if_fail (UNI_IS_IMAGE_VIEW (view));
    view->fitting = fitting;
    gtk_widget_queue_resize (GTK_WIDGET (view));
}

/**
 * uni_image_view_get_pixbuf:
 * @view: A #UniImageView.
 * @returns: The pixbuf this view shows.
 *
 * Returns the pixbuf this view shows.
 **/
GdkPixbuf *
uni_image_view_get_pixbuf (UniImageView * view)
{
    g_return_val_if_fail (UNI_IS_IMAGE_VIEW (view), NULL);
    return view->pixbuf;
}

/**
 * uni_image_view_set_pixbuf:
 * @view: A #UniImageView.
 * @pixbuf: The pixbuf to display.
 * @reset_fit: Whether to reset fitting or not.
 *
 * Sets the @pixbuf to display, or %NULL to not display any pixbuf.
 * Normally, @reset_fit should be %TRUE which enables fitting. Which
 * means that, initially, the whole pixbuf will be shown.
 *
 * Sometimes, the fit mode should not be reset. For example, if
 * UniImageView is showing an animation, it would be bad to reset the
 * fit mode for each new frame. The parameter should then be %FALSE
 * which leaves the fit mode of the view untouched.
 *
 * This method should not be used if merely the contents of the pixbuf
 * has changed. See uni_image_view_damage_pixels() for that.
 *
 * If @reset_fit is %TRUE, the ::zoom-changed signal is emitted,
 * otherwise not. The ::pixbuf-changed signal is also emitted.
 *
 * The default pixbuf is %NULL.
 **/
void
uni_image_view_set_pixbuf (UniImageView * view,
                           GdkPixbuf * pixbuf, gboolean reset_fit)
{
    if (view->pixbuf != pixbuf)
    {
        if (view->pixbuf)
            g_object_unref (view->pixbuf);
        view->pixbuf = pixbuf;
        if (view->pixbuf)
            g_object_ref (pixbuf);
    }

    if (reset_fit)
        uni_image_view_set_fitting (view, TRUE);
    else
    {
        /*
           If the size of the pixbuf changes, the offset might point to
           pixels outside it so we use uni_image_view_scroll_to() to
           make it valid again. And if the size is different, naturally
           we must also update the adjustments.
         */
        uni_image_view_scroll_to (view, view->offset_x, view->offset_y,
                                  FALSE, FALSE);
        uni_image_view_update_adjustments (view);
        gtk_widget_queue_draw (GTK_WIDGET (view));
    }

    g_signal_emit (G_OBJECT (view),
                   uni_image_view_signals[PIXBUF_CHANGED], 0);
    uni_dragger_pixbuf_changed ((UniDragger *) view->tool, reset_fit, NULL);
}

/**
 * uni_image_view_get_zoom:
 * @view: a #UniImageView
 * @returns: the current zoom factor
 *
 * Get the current zoom factor of the view.
 **/
gdouble
uni_image_view_get_zoom (UniImageView * view)
{
    g_return_val_if_fail (UNI_IS_IMAGE_VIEW (view), 1.0);
    return view->zoom;
}

/**
 * uni_image_view_set_zoom:
 * @view: a #UniImageView
 * @zoom: the new zoom factor
 *
 * Sets the zoom of the view.
 *
 * Fitting is always disabled after this method has run. The
 * ::zoom-changed signal is unconditionally emitted.
 **/
void
uni_image_view_set_zoom (UniImageView * view, gdouble zoom)
{
    g_return_if_fail (UNI_IS_IMAGE_VIEW (view));
    zoom = CLAMP (zoom, UNI_ZOOM_MIN, UNI_ZOOM_MAX);
    uni_image_view_set_zoom_no_center (view, zoom, FALSE);
}

/*************************************************************/
/***** Actions ***********************************************/
/*************************************************************/
/**
 * uni_image_view_zoom_in:
 * @view: a #UniImageView
 *
 * Zoom in the view one step. Calling this method causes the widget to
 * immediately repaint itself.
 **/
void
uni_image_view_zoom_in (UniImageView * view)
{
    gdouble zoom;
    zoom = CLAMP (view->zoom * UNI_ZOOM_STEP, UNI_ZOOM_MIN, UNI_ZOOM_MAX);
    uni_image_view_set_zoom (view, zoom);
}

/**
 * uni_image_view_zoom_out:
 * @view: a #UniImageView
 *
 * Zoom out the view one step. Calling this method causes the widget to
 * immediately repaint itself.
 **/
void
uni_image_view_zoom_out (UniImageView * view)
{
    gdouble zoom;
    zoom = CLAMP (view->zoom / UNI_ZOOM_STEP, UNI_ZOOM_MIN, UNI_ZOOM_MAX);
    uni_image_view_set_zoom (view, zoom);
}
