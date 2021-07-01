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

namespace 网上鲜果系统
{
    public partial class 添加 : Form
    {
        public 添加()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string comm = "server = localhost;port=3306;user=root;password=123456;database=shuiguo";
            MySqlConnection sq = new MySqlConnection(comm);
            try
            {
                string sql = string.Format("select count(*) from xianguo where sid='{0}'",textBox1.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                sq.Open();
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看水果是否存在
                if(0 == a)
                {
                    sql = "INSERT INTO xianguo(sid,sname,sdes,sadr,stime,sprice,count) VALUES('" + textBox1.Text + "','" + textBox2.Text + "','" + textBox3.Text + "','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "','" + textBox8.Text + "')";
                    cmd = new MySqlCommand(sql, sq);

                    cmd.ExecuteNonQuery();

                    MessageBox.Show("添加成功！", "信息提示", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    this.Close();
                }
                else
                {
                    sql = string.Format("UPDATE xianguo SET count=count+1 where sid='{0}'", textBox1.Text);
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
