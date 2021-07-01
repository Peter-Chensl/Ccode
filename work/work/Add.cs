using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
namespace work
{
    public partial class Add : Form
    {
        public Add()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)//添加书籍
        {
            string comm = "server = localhost;port=3306;user=root;password=123456;database=book";
            MySqlConnection sq = new MySqlConnection(comm);
            try
            {
                string sql = string.Format("select count(*) from books where bookid='{0}'",textBox1.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                sq.Open();
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看图书是否存在
                if(0 == a)
                {
                    sql = "INSERT INTO books(bookid,bookname,auther,pubish,bookdate,price,leibie,count) VALUES('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "','" + textBox7.Text + "','" + textBox8.Text + "')";
                    cmd = new MySqlCommand(sql, sq);

                    cmd.ExecuteNonQuery();

                    MessageBox.Show("添加成功！", "信息提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();
                }
                else
                {
                    sql = string.Format("UPDATE books SET count=count+1 where bookid='{0}'", textBox1.Text);
                    cmd = new MySqlCommand(sql, sq);

                    cmd.ExecuteNonQuery();

                    MessageBox.Show("更新成功！", "信息提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                Application.Exit();
            }
            finally
            {
                sq.Close();
                sq.Dispose();
            }
        }
    }
}
